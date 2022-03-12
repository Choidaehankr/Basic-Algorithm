#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 200+2
using namespace std;
int arr[MAX][MAX];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int S, X, Y, N, K;

struct Virus {
	int virus;
	int x;
	int y;
};

vector<Virus> vec;

bool comp(Virus &v1, Virus &v2) {
	return v1.virus < v2.virus;  // 바이러스의 크기 순으로 정렬
}

int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int num; cin >> num;
			arr[i][j] = num;
			if (num != 0)
				vec.push_back({num, i, j });  // 바이러스 크기와 위치를 vec에 저장
		}
	}
	cin >> S >> X >> Y;

	for (int i = 0; i < S; i++) {  // S초 만큼 돌 것.
		sort(vec.begin(), vec.end(), comp);  // 매 초마다 바이러스의 크기 순으로 정렬
		int len = vec.size();  // vec 값이 변하지 않도록 초 마다 저장
		for (int j = 0; j < len; j++) {
			Virus v = vec[j];
			for (int k = 0; k < 4; k++) {
				int nx = v.x + dx[k];
				int ny = v.y + dy[k];
				if (nx > 0 && nx <= N && ny > 0 && ny <= N && !arr[nx][ny]) {
					arr[nx][ny] = v.virus;  // 바이러스 전염
					vec.push_back({ arr[nx][ny], nx, ny });  // 다음 탐색을 위해 vec에 push
				}
			}
		}
		if (arr[X][Y] != 0)  // (X, Y)에 값이 이미 있다면, 바뀔 일이 없으므로 조기 종료
			break;
	}
	cout << arr[X][Y];
}