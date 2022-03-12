#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	string str;
	cin >> str;
	stack<char> s;
	int i = 1, sum = 1, tmp = 0;
	bool flag = true;
	//오류 조건: 
	//1. 스택에서 나오는 괄호가 짝이 안맞을 경우
	//2. 문자열이 끝나지 않았는데 스택이 빈 경우 
	//3. for 문이 끝났는데 스택이 비어있지 않은 경우
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			s.push('(');
			sum *= 2; // 여는 '('는 sum에 2를 곱해줌
		}
		else if (str[i] == '[') {
			s.push('[');
			sum *= 3; // 여는 '['는 sum에 3을 곱해줌. 이후 괄호가 완성된다면 tmp에 누적 sum값을 더하고, sum을 2또는 3으로 나눌 것.
		}
		else if (str[i] == ')') { //닫는 ')'를 만났을 때
			if (s.empty()) {
				flag = false; break; //스택이 비어있을 때 오류
			}
			if (s.top() == '(') {
				if (str[i - 1] == '(') // 괄호'(), []'가 완성된 경우
					tmp += sum; // sum에 누적된 값을 tmp에 곱함.
				s.pop();
				sum /= 2; //이미 tmp에 sum을 더해줬으므로 '('면 2, '['면 3을 나눠준다.
			}
			else {
				flag = false; break; //짝이 안맞을 경우 오류
			}
		}
		else if (str[i] == ']') {
			if (s.empty()) {
				flag = false; break;
			}
			if (s.top() == '[') {
				if (str[i - 1] == '[') 
					tmp += sum;
				s.pop();
				sum /= 3;
			}
			else {
				flag = false; break;
			}
		}
	}
	if (!flag || !s.empty()) //오류 조건
		cout << 0 << endl;
	else
		cout << tmp;
}