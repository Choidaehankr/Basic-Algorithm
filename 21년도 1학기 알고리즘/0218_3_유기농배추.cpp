#pragma warning (disable:4996)
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

using namespace std;

int mvX[4] = { 0, 0, 1, -1 }; // 상하좌우 이동
int mvY[4] = {1, -1, 0, 0 };
int map[51][51] = { 0, };
int visited[51][51] = { 0, }; //방문 표시용
int N, M, K;

void dfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int mX = x + mvX[i]; //x좌표를 상하좌우 이동
		int mY = y + mvY[i]; // y좌표를 ""
		if (mX < 0 || mY < 0 || mX >= M || mY >= N)
			continue; //배열 범위에 벗어나면 continue;

		if (map[mX][mY] == 1 && visited[mX][mY] == 0) { //상하좌우 이동 후 배열 상에 배추가 심어져있고 아직 방문을 안했다면
			visited[mX][mY] = 1; //방문했다고 표시하고
			dfs(mX, mY); //계속 dfs 탐색을 진행
		}
	}
}

int main() {
	int T;
	cin >> T;
	while (T > 0) {
		memset(map, 0, sizeof(map)); //배열 초기화
		memset(visited, 0, sizeof(visited));
		int result = 0;
		scanf("%d %d %d", &N, &M, &K);
		for (int i = 0; i < K; i++) {
			int x, y;
			scanf("%d %d", &y, &x); 
			map[x][y] = 1; //배추가 심어졌다고 표시
		}
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 1 && visited[i][j] == 0) { //배추가 심어져있는데 방문을 안했다면
					result++; // 지렁이 증가하고
					visited[i][j] = 1; //방문했다고 표시한 후
					dfs(i, j); // 해당 위치부터 dfs 탐색 시작 (인근 배추 탐색)
				}
			}
		}
		cout << result << endl;
		T--;
	}
}