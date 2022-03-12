#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int board[101][101];
bool visited[101][101];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

queue<pair<int, int>> q;
int w, h;

void bfs() {
	memset(visited, false, sizeof(visited));  // visited 배열을 초기화
	q.push({ 0, 0 });  // 공기인 부분부터 탐색
	visited[0][0] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w || visited[nx][ny])  // 접근 불가 범위
				continue;
			if (board[nx][ny] == 0) {  // 공기라면 계속해서 탐색
				q.push({ nx, ny });
			}
			else {
				board[nx][ny] = 0;  // 치즈라면, 공기와 닿으므로 녹는다고 표시
			}
			visited[nx][ny] = true;
		}
	}
}

bool cheeseCheck() {  // 치즈가 다 녹았는지 확인하는 함수
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (board[i][j] == 1) {
				return false;
			}
		}
	}
	return true;
}

int cheeseCount() {  // 현재 치즈의 개수를 반환하는 함수... countCheeses ...............
	int cheeseCnt = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (board[i][j] == 1) {
				cheeseCnt += 1;
			}
		}
	}
	return cheeseCnt;
}

int main() {
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> board[i][j];
		}
	}
	int curCnt = 0;
	int trial = 0;
	while (1) {
		if (cheeseCheck()) {  // 남아있는 치즈가 없다면 종료
			break;
		}
		curCnt = cheeseCount();  // 다 녹기 전 치즈의 개수를 저장
		bfs();  // 녹는 치즈 탐색
		trial += 1;  // 시간 1증가
	}
	cout << trial << endl << curCnt;
} 