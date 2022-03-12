#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <deque>
using namespace std;

string str = "";

struct tree {
	char left;
	char right;
};
map<char, tree> mp;  // '자기 자신' 과 left, right 값.

void preorder() {  // 전위 순회!
	deque<char> dq;
	dq.push_front('A');  // 시작은 무적권 'A'
	while (!dq.empty()) {
		char c = dq.front();  // dq에 맨 앞에 있는 값을 str에 더해줌
		str += c;
		dq.pop_front();  // 문자열에 더했다면 빼줌
		if (mp[c].left != '.') {  // 왼쪽 먼저 보고, '.'이 아니라면
			dq.push_front(mp[c].left);  // 맨 앞에 추가 (전위 순회 개념)
			if (mp[c].right != '.') {  // 그다음 오른쪽 값을 보고 '뒤에' 추가해줌
				dq.push_back(mp[c].right);
			}
		}
		else {  // 왼쪽 노드가 '.' 이라면
			if (mp[c].right != '.') {  // 오른쪽 노드가 값이 있다면 앞에 추가해줌.
				dq.push_back(mp[c].right);  //일단 push_back / front 결과가 같음 연구 필요
			}
		}
	}
}



int main() {
	int N; cin >> N;
	//char c; cin >> c;
	for (int i = 0; i < N; i++) {
		char rt, l, r;
		cin >> rt >> l >> r;
		mp.insert({ rt, {l, r} });
	}
	preorder();
	cout << str;
}