#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;
	int len = str.length();
	int sum = 0;
	// 1�� �ɷ��� 2�ʰ� �ʿ��ϴ� ���ڿ� �ش��ϴ� ���ڰ� 1�� Ŀ������ sum�� 1�� ����.
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