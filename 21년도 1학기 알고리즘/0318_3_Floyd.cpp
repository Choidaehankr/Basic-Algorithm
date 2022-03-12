#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int dist[101][101];
const int INF = 999999999;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j)
				dist[i][j] = INF;
			else
				dist[i][j] = 0;
		}
	}

	for (int i = 1; i <= m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		dist[a][b] = (dist[a][b] > c) ? c : dist[a][b];	
		//dist[][]배열에 입력시 기존에 있던 가중치보다 크면 무시한다.
	}

	//배열상에 INF인곳 가려면 다 탐색하고 최소값을 따져야함.
	//대칭 구조 상에 있는 원소들은 방문할 수 있음.

	//*핵심*: 노드 i를 기준: x에서 y로 가는 비용 vs (x에서 i로 가는 비용 + i에서 y로 가는비용)

	for (int i = 1; i <= n; i++) {
		for (int x = 1; x <= n; x++) {
			for (int y = 1; y <= n; y++) {
				int cur = dist[x][y];
				dist[x][y] = min(cur, dist[x][i] + dist[i][y]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == INF)
				cout << 0 << ' ';
			else
				cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}
}