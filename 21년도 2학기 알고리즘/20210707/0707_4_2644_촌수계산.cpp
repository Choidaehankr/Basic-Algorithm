#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define MAX 100

int x, y; //x와 y 사이의 촌수를 찾는 것이 목표.
vector<int> v[MAX];
bool visited[MAX];
int result = 0;
void DFS(int start, int end, int cnt) {
	visited[start] = true;
	if (start == end) { //basecase: 방문한 노드가 목표 노드일 경우 누적된 cnt를 result에 넣고 종료
		result = cnt;
		return;
	}

	//기본 dfs 탐색 코드. 블로그 참조
	//해당 vector 크기만큼 돌면서 방문하지 않았을 경우 DFS 함수를 재귀호출해서 모두 방문.
	//여기서 방문 시 인자로 cnt+1 를 해줌으로써 촌수를 증가시킴.
	for (int i = 0; i < v[start].size(); i++) {
		int next = v[start][i];
		if (!visited[next]) {
			DFS(next, end, cnt+1);
		}
	}
}
int main() {
	int num; cin >> num;
	cin >> x >> y;
	int n; cin >> n;
	memset(visited, false, sizeof(visited)); //visit 배열을 false로 모두 초기화
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b); //vector를 통해서 a와 b의 관계를 그래프 형식으로 선언
		v[b].push_back(a);
	}
	DFS(x, y, 0);
	if (result == 0) {
		cout << -1 << endl;
	}
	else cout << result << endl;
}