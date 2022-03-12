#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

//접근: 지도를 입력 받는데, 섬이라면 냅다 벡터 V에 push 해준다. (66)
// 입력을 받고 v크기만큼 돌면서 섬 주변에 바다가 3개 이상인지 check함수로 확인(BFS탐색)해주고 bool타입을 return받는다.
// 섬이 3개 이상이라면 또 다른 result 벡터에 냅다 넣어준다.
// result 벡터에 들어간 섬은 가라앉을 터이니.. '.'으로 바꿔준다.
// 지도를 보기좋게 잘라준다.

#define MAX 0
#define MIN 11
char map[MIN][MIN];

int r, c;
int minR = MIN , maxR = MAX, minC = MIN, maxC = MAX;

int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, 1, -1, 0 };

vector <pair<int, int>> v;
vector<pair<int, int>> result;



bool check(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= r || ny >= c) { //범위를 벗어날 경우 바다이므로 cnt를 증가
			cnt++;
			continue;
		}
		if (map[nx][ny] == '.') {
			cnt++;
		}
	}
	if (cnt >= 3)
		return true;
	else return false;
}

void showResult() {
	// 자를 범위를 정하기 위해 배열의 행과 열의 각각 min, max값을 탐색한다.
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == 'X') {
				minR = min(i, minR);
				maxR = max(i, maxR);
				minC = min(j, minC);
				maxC = max(j, maxC);
			}
		}
	}

	// 자를 범위를 정하고 그대로 출력해주면 끝!
	for (int i = minR; i <= maxR; i++) {
		for (int j = minC; j <= maxC; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			char c;
			cin >> c;
			map[i][j] = c;
			if (c == 'X')
				v.push_back({ i, j });
		}
	}
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first;
		int y = v[i].second;
		bool flag = check(x, y);
		if (flag) {
			result.push_back({ x, y });
		}
	}

	for (int i = 0; i < result.size(); i++) {
		map[result[i].first][result[i].second] = '.';
	}
	showResult();
}