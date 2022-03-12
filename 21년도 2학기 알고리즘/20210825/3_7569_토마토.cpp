#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int box[100][100][100];
int result[100][100][100];
int M, N, H;
int dx[6] = { 0, 0, 0, 0, -1, 1 };
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {-1, 1, 0, 0, 0, 0};
queue <pair<pair<int, int>, int>> q;
int cnt = 0;

void BFS() {
	while (!q.empty()) {
		pair<pair<int, int>, int> now = q.front();
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nz = now.first.first + dz[i];
			int nx = now.first.second + dx[i];
			int ny = now.second + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H || result[nz][nx][ny] >= 0)
				continue;
			result[nz][nx][ny] = result[now.first.first][now.first.second][now.second] + 1; 
			//토마토가 익을 수 있는 상황이면 카운트를 1씩 증가시켜 익는데 걸리는 일을 업데이트
			q.push({ {nz,nx}, ny });
		}
	}
}

int main() {
	cin >> M >> N >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> box[i][j][k];
				if (box[i][j][k] == 1) { //익은 토마토가 있는 위치를 push
					q.push({{i, j}, k});
				}
				if (box[i][j][k] == 0) { //아직 익지 않은 토마토
					result[i][j][k] = -1;
				}
			}
		}
	}
	BFS();
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (result[i][j][k] == -1) { //모두 익지 않았을 경우
					cout << -1;
					return 0;
				}
			cnt = max(cnt, result[i][j][k]);
			}
		}
	}
	cout << cnt;
}