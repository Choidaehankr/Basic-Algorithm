#pragma warning(disable:4996)
#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

int N, M;
int arr[101][101];
int res[101][101] = { 0, };

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };


int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &arr[i][j]); 
		}
	}
	int cnt = 0;
	queue <pair<int, int>> q;
	q.push(make_pair(1, 1));
	res[1][1] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || nx > N || ny < 1 || ny > M) {
				continue;
			}
			if (arr[nx][ny] == 1 && res[nx][ny] == 0) { 
				res[nx][ny] = res[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
	cout << res[N][M] << endl;
}