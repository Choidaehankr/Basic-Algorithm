#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

//pair<int, int> 참고 https://developingbear.tistory.com/58

struct comp { //구조체로 직접 비교: 되는데, 시간 초과, 이것도 블로그 참고
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		if (a.first == b.first) {
			return a.second > b.second;
		}
		else {
			return a.first > b.first;
		}
	}
};

int main() {
	int N;
	cin >> N;
	//priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair <int,int>>> pq;
	//우선순위 큐 pair<int, int>로 선언. 
	for (int i = 1; i <= N; i++) {
		int x; cin >> x;
		if (x != 0) {
			pq.push({abs(x), x}); //x가 0이 아닐경우 {x의 절대값, x 값}으로 저장
			//x의 절대값의 오름차순으로 정렬이 됨.
			//default로 first값이 같을 경우 second값의 오름차순으로 정렬됨(다행)
		}
		else {
			if (pq.empty()) {
				cout << 0 << endl; 
			}
			else {
				cout << pq.top().second << endl; //x의 원래 값을 출력하면 됨.
				pq.pop();
			}
		}
	}
}