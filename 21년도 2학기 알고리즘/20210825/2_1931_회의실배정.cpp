#include <iostream>
#include <queue>
using namespace std;

struct compare {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
//풀이: 회의가 일찍 끝나는 순서대로 정렬이 필요함.
//다음 회의의 시작 시간이 현재 회의의 끝나는 시간보다 크거나 같을때 까지 q.pop()을 해주고,
//조건을 만족한다면, 회의 끝나는 시간을 업데이트 해준다.
int main() {
	long long int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;
		q.push({ end, start });
	}
	int end = q.top().first;
	q.pop();
	int cnt = 1;
	while (!q.empty()) {
		int n_start = q.top().second;
		int n_end = q.top().first;
		q.pop();
		if (n_start >= end) {
			cnt++;
			end = n_end;
		}
	}
	cout << cnt;
}