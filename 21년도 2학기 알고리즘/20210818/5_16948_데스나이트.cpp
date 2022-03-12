  #include <iostream>
#include <queue>
using namespace std;
int chess[200][200];
bool visit[200][200];
int N, r1, c1, r2, c2;
//데스나이트가 움직일 수 있는 위치를 dx, dy 배열에 정리
int dx[6] = { -2, -2, 0, 0, 2, 2 };
int dy[6] = { -1, 1, -2, 2, -1 ,1 };
void BFS(int x, int y) {
	queue<pair<pair <int, int>, int>> q; // <pair<pair<int, int>, int>> 형 queue 선언
	q.push({ { x, y }, 0 });
	visit[x][y] = true;
	while (!q.empty()) {
		int nx = q.front().first.first;
		int ny = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		if (nx == r2 && ny == c2) { //종료 조건
			cout << cnt; return;
		}
		for (int i = 0; i < 6; i++) {
			int mx = nx + dx[i]; int my = ny + dy[i];
			if (mx >= 0 && mx < N && my >= 0 && my < N) {
				if (!visit[mx][my]) {
					visit[mx][my] = true;
					q.push({ { mx, my }, cnt + 1 }); //bfs 탐색마다 cnt를 증가
				}
			}
		}
	}
	cout << -1; // 갈 수 없다면 -1 출력
}
int main() {
	cin >> N;
	cin >> r1 >> c1 >> r2 >> c2;
	BFS(r1, c1);
}