#include <iostream>
#include <string>
using namespace std;
// I=1, V=5, X=10, L=50, C=100, D=500, M=1000

int rome_to_int(string str) {
	char prev_c = ' ';
	int sum = 0;
	for (int i = 0; i < str.size(); i++) {
		char c = str[i];
		if (c == 'V') {
			if (prev_c == 'I')  // 이전 루프를 돌면서 값을 추가해줬기 때문에, 
				sum += 3;  // prev_c가 조건을 만족하는 경우 sum에서 prev_c만큼 빼줘야함.
			else sum += 5;
		}
		else if (c == 'X') {
			if (prev_c == 'I')
				sum += 8;
			else sum += 10;
		}
		else if (c == 'L') {
			if (prev_c == 'X')
				sum += 30;
			else sum += 50;
		}
		else if (c == 'C') {
			if (prev_c == 'X')
				sum += 80;
			else sum += 100;
		}
		else if (c == 'D') {
			if (prev_c == 'C')
				sum += 300;
			else sum += 500;
		}
		else if (c == 'M') {
			if (prev_c == 'C')
				sum += 800;
			else sum += 1000;
		}
		else if (c == 'I')
			sum += 1;
		prev_c = c;
	}
	return sum;
}

string int_to_rome(int num) {
	string tmp;

	int n = num / 1000;  // 1000의 자리
	num %= 1000;
	for (int i = 0; i < n; i++)
		tmp += 'M';

	// 천의 자리를 제외하고, n이 4와 9일 경우에 작은 값이 앞에 나올 수 있으므로, 조건을 따로 빼줌

	n = num / 100;  // 100의 자리
	num %= 100;
	
	if (n == 4 || n == 9) {  
		tmp += 'C';
		if (n == 4) tmp += 'D';
		if (n == 9) tmp += 'M';
		}
	else {
		if (n >= 5) {  // n이 4와 9가 아니며, 5보다 클 경우는 V(5), L(50), D(500)를 붙여줘야함.
			tmp += 'D'; 
			n -= 5;
		}
		// 이후 I(1), X(10), C(100) 을 남은 자리수 만큼 추가해줌 
		for (int i = 0; i < n; i++) tmp += 'C';
	}

	n = num / 10;  // 10의 자리
	num %= 10;
	if (n == 4 || n == 9) {
		tmp += 'X';
		if (n == 4) tmp += 'L';
		if (n == 9) tmp += 'C';
	}
	else {
		if (n >= 5) {
			tmp += 'L';
			n -= 5;
		}
		for (int i = 0; i < n; i++) tmp += 'X';
	}

	n = num;  // 1의 자리
	if (n == 4 || n == 9) {
		tmp += 'I';
		if (n == 4) tmp += 'V';
		if (n == 9) tmp += 'X';
	}
	else {
		if (n >= 5) {
			tmp += 'V';
			n -= 5;
		}
		for (int i = 0; i < n; i++) tmp += 'I';
	}
	return tmp;

}int main() {
	string str1, str2, result;
	cin >> str1 >> str2;
	int sum = rome_to_int(str1) + rome_to_int(str2);
	result = int_to_rome(sum);
	cout << sum << endl << result;
}