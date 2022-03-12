#include <iostream>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> q;
int main() {
	int N, L;
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		q.push(num);
	}
	while (!q.empty()) {
		int num = q.top();
		q.pop();
		if (L >= num) {
			L += 1;
		}
		else {
			break;
		}
	}
	cout << L << endl;
}