#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

#define SHARK 1
int col, row;
int sea[50][50];
bool visit[50][50];
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

vector<pair<int, int>> v;

//배열을 입력받을때 상어가 아닌 '0'을 입력 받게 되면 vector에 해당 행,열을 push_back
//vector.size()만큼 for문을 돌면서 해당 행,열을 bfs 탐색. 탐색 중 SHARK를 만나기 까지 칸 수 (cnt) 값을 증가하고, 상어를 만난다면 탐색 종료.
//bfs탐색으로 얻은 탐색 횟수 (안전거리)의 최댓값을 구함.

//int BFS(int nx, int ny, int cnt) {
int BFS(int nx, int ny) {
	queue<pair<pair<int, int>, int>> q;
	memset(visit, false, sizeof(visit));
	q.push(make_pair(make_pair(nx, ny), 0));  //초기의 탐색 횟수는 0으로 설정
	visit[nx][ny] = true;
	while (!q.empty()) {
		int x = q.front().first.first; //queue에 존재하는 col 값
		int y = q.front().first.second; // queue에 존재하는 row 값
		int result = q.front().second; // queue에 존재하는 최종적으로 필요한 안전거리 값
		q.pop();
		if (sea[x][y] == SHARK) // 상어를 만나게 된다면 result를 반환하며 종료. (안전거리의 끝)
			return result;
		for (int i = 0; i < 8; i++) { //8방향 탐색
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			if (next_x < 0 || next_x >= col || next_y < 0 || next_y >= row || visit[next_x][next_y])
				continue; // 기본 탐색 조건
			visit[next_x][next_y] = true;
			q.push(make_pair(make_pair(next_x, next_y), result + 1)); //result 값을 1씩 늘려가며 BFS탐색
		}
	}
	return 0;
}

int main() {
	cin >> col >> row;
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			int num; cin >> num;
			sea[i][j] = num;
			if (num == 0)
				v.push_back({ i, j }); // 상어가 없는 빈칸이라면 vector에 push_back
		}
	}
	int max_num = -1;
	for (int i = 0; i < v.size(); i++) {
		int nx = v[i].first;
		int ny = v[i].second;
		int cnt = BFS(nx, ny); //상어를 찾기 위해서 nx, ny 위치를 BFS 탐색

		max_num = max(max_num, cnt); // 가장 큰 안전거리를 탐색한다.
	}
	cout << max_num;
}