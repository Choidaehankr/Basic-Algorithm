#include <iostream>
#include <vector>
#include <cstring>
#include <math.h>
using namespace std;

#define MAX 51
int arr[MAX][MAX];
bool visited[MAX][MAX];

int N = 0, L, R;
int result = 0;
int cnt, sum;
vector<pair<int, int>> v;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void solution(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!visited[x][y]) {
			if (y >= 0 && y < N && x >= 0 && x < N) {
				if (abs(arr[x][y] - arr[nx][ny] >= L && abs(arr[x][y] - arr[nx][ny] <= R))) {
					visited[nx][ny] = 1;
					cnt++;		//연합 국가 수
					sum += arr[nx][ny];		//인구수의 합
					v.push_back({ nx, ny });
					solution(nx, ny);
				}
			}
		}
	}
}

int main() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	while (1) {
		bool flag = false;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) {
					v.clear();
					cnt = 1;
					sum = arr[i][j];
					visited[i][j] = true;
					v.push_back({ i, j });
					solution(i, j);
					if (cnt >= 2) {
						flag = true;
						int population = sum / cnt;
						for (int k = 0; k < v.size(); k++) {
							arr[v[k].first][v[k].second] = population;
						}
					}
				}
			}
		}
		if (flag == true)
			break;
		else
			result++;
	}
	cout << result << endl;
}