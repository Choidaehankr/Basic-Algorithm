#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int mx[8] = { -1, -2, -2, -1, 1, 2, 2, 1 }; //나이트가 이동 가능한 방향을 x, y축으로 묶음
int my[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
bool visited[300][300] = {false,};
int l;
int s_row, s_col, d_row, d_col; //s_row, s_col: 시작 행과 열, d_row, d_col: 목적지 행과 열
void bfs(int row, int col) {
	//기본 bfs의 개념은 그냥 외워버렸습니다. 기본적으로 queue를 사용, 이동가능한 방향을 mx, my 배열에 넣어두고 for루프를 돌며
	//접근할 수 없는 배열과 방문했던 배열을 PASS하며 방문할 수 있으면 VISIT배열여부를 true로 해주고 q에 push해주는 방법.

	queue<pair<pair<int, int>, int>> q; //접근할 x,y축의 위치와 접근 횟수를 같이 묶기위해 pair를 2번 씀.
	q.push(make_pair(make_pair(row, col), 0)); //시작 위치를 queue에 push하고 방문했다고 표시. 초기 방문 횟수를 0으로 초기화
	visited[row][col] = true;

	while (!q.empty()) {
		int n_row = q.front().first.first; //n_row, n_col : 현재 queue에 있는 x, y 축
		int n_col = q.front().first.second;
		int result = q.front().second; // 방문 횟수
		q.pop();
		if (n_row == d_row && n_col == d_col) { // 원하는 위치에 도달하면 값을 출력 후 종료
			cout << result << endl;
			return;
		}
		for (int i = 0; i < 8; i++) {
			int nextX = n_row + mx[i]; // 접근할 수 있는 x, y축을 모두 접근
			int nextY = n_col + my[i];
			if (nextY >= 0 && nextY < l && nextX >= 0 && nextX < l) { // 접근할 수 있는 위치 (존재하는 배열) 이고, 
				if (!visited[nextX][nextY]) { //방문하지 않았다면,
					visited[nextX][nextY] = true; // 방문했다고 표시 한 후 queue에 push
					q.push(make_pair(make_pair(nextX, nextY), ++result)); // result++로 해서 계속 틀렸음. 이유는 모르겠
				}
			}
		}
	}
}

int main() {
	int testcase; cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		cin >> l;
		cin >> s_row >> s_col;
		cin >> d_row >> d_col;
		memset(visited, false, sizeof(visited)); //loop마다 visited 배열을 초기화
		bfs(s_row, s_col);
	}
}