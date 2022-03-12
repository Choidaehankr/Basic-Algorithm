#include <iostream>
#include <queue>
using namespace std;

int main() {
	priority_queue<int, vector<int>, greater<int>> pq;
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int num = 0;
		cin >> num;
		if (num == 0 && pq.empty()) //입력값이 0이고 pq가 비어있다면 0을 출력
			cout << 0 << endl;
		else if (num == 0) { // num이 0이라면 가장 위에 있는 값을 출력
			cout << pq.top() << endl;
			pq.pop();
		}
		else {
			pq.push(num); //외의 경우 push
		}
	}
}