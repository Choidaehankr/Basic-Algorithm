#include <iostream>
#include <cstring> // memset
#include <queue>
using namespace std;

//처음 아기상어 크기: 2
//한 번 이동: 1초
//자신 보다 큰 물고기있는 칸은 지날 수 없음
//자신 보다 작은 물고기만 먹을 수 있음
//더 이상 먹을 수 있는 물고기가 공간에 없다면 아기 상어는 엄마 상어에게 도움을 요청
//먹을 수 있는 물고기가 1마리라면, 그 물고기를 먹으러 간다.
//먹을 수 있는 물고기가 1마리보다 많다면, 거리가 가장 가까운 물고기를 먹으러 간다.
//거리가 가까운 물고기가 많다면, 가장 위에 있는 물고기, 맨 왼쪽에 있는 물고기를 먹는다.
//아기 상어는 자신의 크기와 같은 수의 물고기를 먹을 때 마다 크기가 1 증가한다.

int arr[20][20] = {};
int cnt_arr[20][20] = {};
bool visited[20][20] = {};
int N; 
int s_col, s_row;
int time_cnt = 0;
int mv_c[4] = {-1, 1, 0, 0};
int mv_r[4] = {0, 0, -1, 1};
queue<pair <pair<int, int>, int>> q; // <<col, row>, 아기상어 크기>
int shark_size = 2;
int shark_eat = 0;
// 더 이상 먹을 물고기가 없다면, 종료...
// -> 자신보다 크거나 같은 물고기만 있거나, 물고기가 아예 없거나.
int min_fish = 6;
void BFS(int col, int row) {
	//q.push(make_pair(make_pair(col, row), 2));
	q.push(make_pair(make_pair(col, row), 0));
	visited[col][row] = true;

	while (!q.empty()) {
		int qSize = q.size();
		while (qSize--) {
			int now_col = q.front().first.first;
			int now_row = q.front().first.second;
			//int babyshark = q.front().second;
			int shark_eat = q.front().second;
			q.pop();
			//time_cnt += 1;
			if (shark_eat >= shark_size) {
				shark_size += 1;
			}
			for (int i = 0; i < 4; i++) {
				int next_col = now_col + mv_c[i];
				int next_row = now_row + mv_r[i];
				if (next_col >= 0 && next_col < N && next_row >= 0 && next_row < N) {
					if (!visited[next_col][next_row]) {
						//time_cnt+=1;
						if (arr[next_col][next_row] <= shark_size) { //지나갈수있
							visited[next_col][next_row] = true;
							cnt_arr[next_col][next_row] += 1;
							//q.push(make_pair(make_pair(next_col, next_row), shark_eat));
							if (arr[next_col][next_row] < shark_size && arr[next_col][next_row] != 0) {
								arr[next_col][next_row] = 0; // 잡아먹음
								q.push(make_pair(make_pair(next_col, next_row), ++shark_eat));
							}
							else {
								q.push(make_pair(make_pair(next_col, next_row), shark_eat));
							}
							time_cnt++;
						 }
					}
				}
			}
		}
	}
	cout << time_cnt << endl;
}

int main() {
	cin >> N;
	memset(visited, sizeof(visited), false);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				s_col = i; s_row = j;
			}
		}
	}
	BFS(s_col, s_row);
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			cout << cnt_arr[i][j] << ' ';
		}
		cout << endl;
	}
}