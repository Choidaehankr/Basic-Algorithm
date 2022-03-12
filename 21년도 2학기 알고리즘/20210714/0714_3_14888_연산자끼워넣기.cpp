#include <iostream>
#include <algorithm>
using namespace std;

int n; 
int calc[4] = { };
int num[11] = {};

int max_num = -1000000000, min_num = 1000000000; //항상 -10억보다 크거나 같고, 10억보다 작거나 같은 결과

void solve(int idx, int sum, int plus, int minus, int multi, int div) {
	if (idx == n) { // index가 초기 입력 받은 n과 같아지면, 최대-최솟값을 구하고 종료
		max_num = max(max_num, sum);
		min_num = min(min_num, sum);
		return;
	}
	// 연산자의 개수가 0이상 이라면 재귀호출. sum에 해당 값을 적절히 연산해주고, 연산자 개수를 -1 해줌

	if (plus > 0) { 
		solve(idx + 1, sum + num[idx], plus - 1, minus, multi, div);
	}
	if (minus > 0) {
		solve(idx + 1, sum - num[idx], plus, minus - 1, multi, div);
	}
	if (multi > 0) {
		solve(idx + 1, sum * num[idx], plus, minus, multi - 1, div);
	}
	if (div > 0) {
		solve(idx + 1, (int)(sum / num[idx]), plus, minus, multi, div - 1);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> calc[i];
	}
	solve(1, num[0], calc[0], calc[1], calc[2], calc[3]); // num[0]에 있는 값은 기본으로 주어짐. index는 1부터 시작.

	cout << max_num << endl << min_num;
}