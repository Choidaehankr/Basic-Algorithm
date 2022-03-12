// 1926 그림

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 500
int n, m;
int arr[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int maxSize = 0;
int drawingCount = 0;
int cnt = 0;

void DFS(int x, int y) {
	visited[x][y] = true;
	cnt += 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {	//배열의 범위를 벗어나지 않고
			if (!visited[nx][ny] && arr[nx][ny]) {		//방문 가능, 그림이라면
				DFS(nx, ny);							//DFS 함수 재귀호출
			}
		}
	}
	maxSize = max(maxSize, cnt); // DFS 탐색을 마치면, 가장 넓은 그림을 찾기 위한 max함수
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && arr[i][j]) { //모든 배열을 탐색하며 이전에 방문하지 않았고, 그림이라면 DFS함수 호출
				DFS(i, j);
				drawingCount += 1;			   //DFS 함수가 호출된다는 것은 새로운 영역의 그림을 발견한 것, 그림 개수 증가
				cnt = 0;					   //가장 넓은 그림을 찾기 위해 cnt를 초기화
			}
		}
	}
	cout << drawingCount << endl << maxSize;
}
