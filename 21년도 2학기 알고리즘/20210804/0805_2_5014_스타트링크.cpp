#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

#define MAX 1000001
int total, now, dest, U, D, cnt;
bool visit[MAX];
bool flag = false;

void BFS() {
	queue<pair<int, int>> q;
	q.push(make_pair(now, 0)); //현재 있는 층수와 시도횟수를 초기 push
	visit[now] = true;
	// 현재 있는 층수에서 U, D를 빼거나 더한 값이 범위 내에 있고, 방문하지 않았다면 queue에 push 해주는 탐색을 시도
	while (!q.empty()) {
		int next = q.front().first;
		int result = q.front().second;
		q.pop();

		if (next == dest) {
			cout << result; //종료 조건
			return;
		}
		if (next + U <= total && !visit[next+U]) {
			visit[next + U] = true;
			q.push(make_pair(next + U, result + 1));
		}
		if (next - D > 0 && !visit[next-D]) {
			visit[next - D] = true;
			q.push(make_pair(next - D, result + 1));
		}
	}
	cout << "use the stairs";
}

int main() {
	cin >> total >> now >> dest >> U >> D;
	BFS();
}