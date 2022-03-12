#pragma warning (disable:4996)	
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 50
int arr[MAX][MAX];
int check[MAX][MAX];
bool visited[MAX][MAX];
int result = 0;
int w, h;
int dx[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int dy[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };

// arr와 같은 크기의 check 배열과 visited배열을 선언
// 위치 파악을 위한 check, 방문 여부 확인을 위한 visited
// check를 통해 배열의 위치를 파악하고 queue에 push
// 탐색을 시작한다면 visited[][]를 true, check[][]를 0


void bfs(int i, int j) {
	queue<int> q;
	q.push(check[i][j]); //queue 에 check(섬의 번호)를 push
	visited[i][j] = true; // 방문 표시
	check[i][j] = 0; // check를 0으로
	while (!q.empty()) {
		q.pop(); 
		for (int k = 0; k < 8; k++) {
			int x = i + dx[k]; //상하좌우 대각선 이동
			int y = j + dy[k];

			if (x < 0 || x >= w || y < 0 || y >= h)
				continue; //배열의 범위 유지
			if (arr[x][y] == 0 && visited[x][y] == false && //계속 탐색
				check[i][j] != 0) {
				q.push(check[x][y]); 
				visited[x][y] = true;
			}
		}
	}
}

int main() {
	while (1) {
		int num = 1;
		scanf("%d %d", &h, &w);
		if (w == 0 && h == 0)
			break;
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				cin >> arr[i][j]; //arr[][]에 섬과 땅을 입력받음
				check[i][j] = num++; //check함수로 arr[][]의 위치를 파악
				/* 1 2 3
				   4 5 6
				   7 8 9*/
			}
		}

		//visited에 방문하지 않았고, 섬이고, check가 0이 아니라면(위치에 해당하는
		//숫자라면) result 증가 후 bfs 탐색 시작
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				if (arr[i][j] == 1 && visited[i][j] == false 
					&& check[i][j] != 0) {
					result++;
					bfs(i, j);
				}
			}
		}
		cout << result << endl;
		/*memset(visited, 0, sizeof(visited));
		memset(check, 0, sizeof(check));*/
		result = 0;
	}
}
