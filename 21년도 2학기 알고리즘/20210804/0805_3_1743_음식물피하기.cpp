#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int arr[101][101];
bool visit[101][101];
vector<pair<int, int>> v;
int r, c, N;
int result = 0;

int BFS(int row, int col) {
	int cnt = 1;
	queue<pair<int, int>> q;
	q.push({ row, col });
	visit[row][col] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx > r || ny < 0 || ny > c) continue; //배열의 범위 지정
			if (visit[nx][ny] || !arr[nx][ny]) continue; // 방문 및 음식물 존재 여부 확인
			visit[nx][ny] = true;
			cnt++;
			q.push({ nx, ny });
		}
	}
	return cnt; //찾은 음식물 갯수 return
}

int main() {
	cin >> r >> c >> N;
	for (int i = 0; i < N; i++) {
		int nr, nc;
		cin >> nr >> nc;
		arr[nr][nc] = 1;
		v.push_back({ nr, nc }); //음식물의 행,열 좌표를 vector에 push
	}
	for (int i = 0; i < N; i++) {
		int nr = v[i].first;
		int nc = v[i].second;
		//음식물이 존재하는 좌표 중 방문하지 않았을 경우 BFS탐색 시작.
		if (!visit[nr][nc])
			result = max(result, BFS(nr, nc));
	}
	cout << result;
}
