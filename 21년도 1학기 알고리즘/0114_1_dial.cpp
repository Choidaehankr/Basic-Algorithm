#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;
	int len = str.length();
	int sum = 0;
	// 1을 걸려면 2초가 필요하니 문자에 해당하는 숫자가 1씩 커질수록 sum을 1씩 증가.
	for (int i = 0; i < len; i++) {
		char c = str.at(i);
		if (c == 'A' || c == 'B' || c == 'C')
			sum += 3;
		else if (c == 'D' || c == 'E' || c == 'F')
			sum += 4;
		else if (c == 'G' || c == 'H' || c == 'I')
			sum += 5;
		else if (c == 'J' || c == 'K' || c == 'L')
			sum += 6;
		else if (c == 'M' || c == 'N' || c == 'O')
			sum += 7;
		else if (c == 'P' || c == 'Q' || c == 'R' || c == 'S')
			sum += 8;
		else if (c == 'T' || c == 'U' || c == 'V')
			sum += 9;
		else
			sum += 10;
	}
	cout << sum;
}