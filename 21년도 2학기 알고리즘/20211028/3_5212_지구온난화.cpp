#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

//����: ������ �Է� �޴µ�, ���̶�� ���� ���� V�� push ���ش�. (66)
// �Է��� �ް� vũ�⸸ŭ ���鼭 �� �ֺ��� �ٴٰ� 3�� �̻����� check�Լ��� Ȯ��(BFSŽ��)���ְ� boolŸ���� return�޴´�.
// ���� 3�� �̻��̶�� �� �ٸ� result ���Ϳ� ���� �־��ش�.
// result ���Ϳ� �� ���� ������� ���̴�.. '.'���� �ٲ��ش�.
// ������ �������� �߶��ش�.

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
		if (nx < 0 || ny < 0 || nx >= r || ny >= c) { //������ ��� ��� �ٴ��̹Ƿ� cnt�� ����
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
	// �ڸ� ������ ���ϱ� ���� �迭�� ��� ���� ���� min, max���� Ž���Ѵ�.
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

	// �ڸ� ������ ���ϰ� �״�� ������ָ� ��!
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