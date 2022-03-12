#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

//A가 B를 신뢰한다. 입력 순서를 거꾸로 받아서 즉, B를 해킹하면 A도 털 수 있다.

#define MAX 10001
vector<int> v[MAX];
vector<pair<int, int>> ans;
bool visit[MAX];
int max_num = 0;
queue<int> q;

void BFS(int index) {
	memset(visit, false, sizeof(visit));
	int cnt = 1;
	q.push(index);
	visit[index] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int y = v[x][i];
			if (!visit[y]) {
				q.push(y);
				visit[y] = true;
				cnt++;
			}
		}
	}
	ans.push_back({ index, cnt }); // ans에는 {컴퓨터 번호, 털 수 있는 갯수}가 들어감
	max_num = max(cnt, max_num);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, M; 
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		v[B].push_back(A);
	}
	for (int i = 1; i <= N; i++) {
		BFS(i);
	}
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i].second >= max_num) 
			cout << ans[i].first << ' ';
	}
}