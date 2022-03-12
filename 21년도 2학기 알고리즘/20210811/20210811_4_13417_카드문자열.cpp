#include <iostream>
#include <deque>
using namespace std;

//가장 처음에 가져온 카드는 자신의 앞에 놓는다.그다음부터는 가져온 카드를 자신의 앞에 놓인 카드들의 가장 왼쪽, 또는 가장 오른쪽에 
// 놓는다.태욱이는 모든 카드를 다 가져온 후에 자신의 앞에 놓인 카드를 순서대로 이어 붙여 카드 문자열을 만들려고 한다.

//deque을 사용해서 문자 c와 현재 deque에 맨처음 있는 문자를 사전순으로 비교해서 왼쪽에 놓을지 오른쪽에 놓을지만 정하면 됨.
int main() {
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		deque<char> dq;
		int num; cin >> num;
		for (int j = 0; j < num; j++) {
			char c; cin >> c;
			if (dq.empty()) {
				dq.push_front(c);
				continue; //goot!!
			}
			if (dq.front() < c) {
				dq.push_back(c);
			}
			else {
				dq.push_front(c);
			}
		}
		for (auto it = dq.begin(); it != dq.end(); it++) {
			cout << *it;
		}
		cout << endl;
	}
}