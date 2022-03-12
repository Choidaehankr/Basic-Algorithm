#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int N;
int arr[100][100];
bool visit[100][100];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void solve(int x, int y, int height) {
	for (int i = 0; i < 4; i++) { //4방향 이동을 통해서 접근 가능한 배열이면서 물에 잠기지 않은 안전 영역을 dfs탐색.
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N || arr[nx][ny] <= height || visit[nx][ny])
			continue;
		visit[nx][ny] = true; 
		solve(nx, ny, height); //dfs탐색을 위한 재귀 호출
	}
}

int main() {
	cin >> N;
	int max_height = 0, min_height = 0;
	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			max_height = max(max_height, arr[i][j]); //입력받은 지역 높이의 최대, 최솟값을 파악
			min_height = min(min_height, arr[i][j]);
		}
	}
	for (int i = min_height; i < max_height; i++) { // i는 물의 높이의 변화
		int cnt = 0;
		memset(visit, false, sizeof(visit)); //물의 높이 (i)가 변할때마다 잠기는 지역이 바뀔 수 있기 때문에 memset함수 호출
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (arr[j][k] > i && !visit[j][k]) { //물에 잠기지 않았고(arr[j][k] > i), 방문하지 않았다면 탐색 시작
					visit[j][k] = true;
					cnt++; //인접한 안전 영역을 탐색할때 마다 cnt를 증가
					solve(j, k, i);
				}
			}
		}
		result = max(result, cnt);
	}
	cout << result;
}