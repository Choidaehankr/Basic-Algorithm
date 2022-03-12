#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 21
using namespace std;

// 'A' = 65, 'Z' = 90
// visited 사용 안함.

bool alpha_check[91];
char board[MAX][MAX];

int R, C;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int cnt, check_num = 0;

int alpha_to_int(char c) {
	return (int)c;
}

void DFS(int x, int y, int dist) {
	cnt = max(cnt, dist);
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		int check_num = alpha_to_int(board[nx][ny]);
		if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
			if (!alpha_check[check_num]) {
				alpha_check[check_num] = true;
				DFS(nx, ny, dist + 1);
				alpha_check[check_num] = false;  // 중요 트릭
			}
		}
	}
}


int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];
		}
	}
	check_num = alpha_to_int(board[0][0]);
	alpha_check[check_num] = true;
	DFS(0, 0, 1);
	cout << cnt << endl;
}