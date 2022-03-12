#include <iostream>
#include <queue>
#define MAX 100000
using namespace std;
// cur+1, cur-1
// cur+A, cur+B, cur-A, cur-B
// cur*A, cur*B

bool visited[MAX];
int A, B, cur, dest;  // A, B: 콩콩이 힘, M을 넘어가면 안됨.
int solution(int x) {
	queue<pair<int, int>> q;
	q.push({ x, 0 });
	visited[x] = true;
	while (!q.empty()) {
		int now = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (now == dest)
			return cnt;
		int mov[8] = { now - 1, now + 1, now - A, now + A, now - B, now + B, now*A, now*B };
		for (int i = 0; i < 8; i++) {
			if (mov[i] >= 0 && mov[i] <= MAX) {
				if (!visited[mov[i]]) {
					visited[mov[i]] = true;
					q.push({ mov[i], cnt + 1 });
				}
			}
		}
	}
}

int main() {
	cin >> A >> B >> cur >> dest;
	cout << solution(cur);
}