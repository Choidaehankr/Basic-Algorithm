#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

string VPScheck(string str);

int main() {
	vector<string> v;
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		string str;
		cin >> str;
		v.push_back(VPScheck(str));
	}
	for (auto it = v.begin(); it != v.end(); it++) {
		cout << *it << endl;
	}
}

string VPScheck(string str) {
	stack<char> s;
	bool check = true;
	int len = str.length();
	int left = 0, right = 0;
	for (int i = 0; i < len; i++) {
		s.push(str.at(i));

	}
	// 닫는 괄호 ')'가 여는 괄호 '('보다 커지면 안됨
	// ')'와 '('의 개수가 다르면 NO
	for (int i = 0; i < len; i++) {		
		if (s.top() == ')')
			left++;
		else
			right++;
		s.pop();
		if (right > left) {
			check = false;
			break;
		}
	}
	if (right != left)
		check = false;

	if (!check)
		return "NO";
	else
		return "YES";
}