#include <iostream>
using namespace std;

int main() {
	string str;
	cin >> str;
	char firstChar = str[0];
	int cnt = 0;
	// 문자열은 0과 1로 이루어져 있어서, 첫번째 문자가 0일 경우, 총 1의 개수를 구하는게 아니라,
	// 1이 연속해서 나타나는 부분의 개수를 구하는 것!

	// 즉, 직전 문자와 동일하지 않고, str의 첫번째 문자와 같지 않을 경우에만 cnt를 증가

	for (int i = 1; i < str.length(); i++) {
		char c = str[i];
		if (str[i - 1] != c && c != firstChar)
			cnt++;
	}
	cout << cnt;
}