#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int get_int_sum(string str) {
	int sum = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] - '0' >= 1 && str[i] - '0' <= 9) // 각 문자가 정수라면 sum에 그 합을 더함
			sum += str[i] - '0';
	}
	return sum;
}

bool comp(string x, string y) {
	if (x.length() != y.length()) {  // 1번 조건. 짧은 것을 반환 
		return x.length() < y.length();
	}
	else {
		int x_sum = get_int_sum(x);
		int y_sum = get_int_sum(y);
		if (x_sum != y_sum)  // 합이 다르다면 정수의 합이 작은 것을 반환
			return x_sum < y_sum;
		else  // 같다면 사전순으로 비교해서 반환
			return x < y;
	}
}

int main() {
	int N; cin >> N;
	vector <string> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end(), comp);
	for (int i = 0; i < N; i++) {
		cout << v[i] << endl;
	}
}