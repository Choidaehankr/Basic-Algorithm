#include <iostream>
#include <queue>
#define MAX 251
using namespace std;
int M, N;
int banner[MAX][MAX];
int dx[8] = { -1, 0, 1, 0, -1, -1, 1, 1};
int dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1};
queue<pair<int, int>> q;
/*
void solution(int x, int y) {
	q.push({ x, y });
	banner[x][y] = 0;
	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = curX + dx[i];
			int ny = curY + dy[i];
			if (nx < 0 || nx >= M || ny < 0 || ny >= N || !banner[nx][ny])
				continue;
			q.push({ nx, ny });
			banner[nx][ny] = 0;
		}
	}
}
*/
void solution(int x, int y) {  // 1인 부분을 발견했다면, 계속 1을 탐색하면서 해당 부분을 0으로 초기화
	banner[x][y] = 0;
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= M || ny < 0 || ny >= N || !banner[nx][ny])
			continue;
		solution(nx, ny);
	}
}

int main() {
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> banner[i][j];
		}
	}
	int cnt = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			//if (banner[i][j] == 1 && !visited[i][j]) {
			if (banner[i][j] == 1) {
				solution(i, j);
				cnt += 1;
			}
		}
	}
	cout << cnt;
}