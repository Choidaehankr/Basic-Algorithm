#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string S, T;
	cin >> S >> T;
	bool result = false; // 결과값 변수
	int s_len = S.length();
	//S를 T로 만드는 과정 (뒤에 'A'추가, 뒤집어서 'B'추가)에서
	//S를 T로 만들고 나서, 반대로 T에서 S로 돌아갈 수 있음. 즉, T를 pop_back해주면서 S로 만들 수 있음.

	//T의 크기에서 시작해서 문자를 하나씩 검사. pop_back() 해주고 만약 'B'라면 reverse함수 사용.
	while (1) {	
		if (s_len == T.length()) {
			if (S == T)
				result = true;
			break;
		}
		if (T[T.length() - 1] == 'A') {
			T.pop_back();
		}
		else {
			T.pop_back();
			reverse(T.begin(), T.end());
		}
	}
	cout << result;
}