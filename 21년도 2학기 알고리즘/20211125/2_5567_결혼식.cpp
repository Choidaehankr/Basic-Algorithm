#include <iostream>
#include <vector>
#include <queue>
#include <set>
#define MAX 501
using namespace std;

vector<int> v[MAX];
bool check[MAX];
int cnt = 0;
queue<int> q;

int main() {
	int N; cin >> N;
	int M; cin >> M;
	for (int i = 1; i <= M; i++) {
		int x, y; 
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	q.push(1);  
	check[1] = true;
	for (int i = 0; i <= v[1].size(); i++) {  // 상근이의 친구들만 검색해주면 됨.
		int cur = q.front();
		q.pop();
		for (int j = 0; j < v[cur].size(); j++) {
			int nx = v[cur][j];
			if (!check[nx]) {  // 방문 처리
				check[nx] = true;
				q.push(nx);
				cnt++;
			}
		}
	}
	cout << cnt;
}