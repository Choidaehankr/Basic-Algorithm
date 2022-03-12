#include <iostream>
#include <vector>
using namespace std;
int n, m;
int s, e;
int result = 0;
vector<vector<int>> adjArray; // 그래프를 작성을 위한 vector
vector<int> visited; // 컴퓨터의 방문 여부를 알기 위한 배열

void addEdge(int start, int end) {
	adjArray[start].push_back(end);
	adjArray[end].push_back(start);
}

void DFS(int x) {
	visited[x] = 1; // x번 컴퓨터를 방문했다고 표시
	for (int i = 0; i < adjArray[x].size(); i++) { //x컴퓨터의 연결된 컴퓨터 만큼
		int z = adjArray[x][i]; // 연결된 컴퓨터를 대입
		if (visited[z] == 0) { //방문을 안했다면
			DFS(z); //재귀함수 DFS()
			result++;
		}
	}
}

int main() {
	cin >> n;
	cin >> m;
	adjArray.resize(n + 1);
	visited.resize(n + 1);

	for (int i = 0; i < m; i++) {
		cin >> s >> e;
		addEdge(s, e);
	}
	for (int i = 1; i <= n; i++)
		visited[i] = 0;
	DFS(1);
	cout << result;
}