#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 연산자 끼워넣기 1 과 동일한 코드로 해결.
int N;
int max_num = -1000000000, min_num = 1000000000;
vector <int> v;
int op[4] = {};
void solve(int index, int sum, int plus, int minus, int multi, int div) {
	if (index >= N) { // 모든 수를 연산하게 된다면 종료.
		max_num = max(max_num, sum);
		min_num = min(min_num, sum);
		return;
	}
	//각 연산자의 개수가 0개 이상이라면, sum에 해당 연산(+, -, *, %)을 수행한 후 개수를 1 감소. solve함수를 재귀 호출
	if (plus > 0) {
		solve(index + 1, sum + v[index], plus-1, minus, multi, div);
	}
	if (minus > 0) {
		solve(index + 1, sum - v[index], plus, minus-1, multi, div);
	}
	if (multi > 0) {
		solve(index + 1, sum * v[index], plus, minus, multi-1, div);
	}
	if (div > 0) {
		solve(index + 1, sum / v[index], plus, minus, multi, div-1);
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		v.push_back(num);
	}
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}
	solve(1, v[0], op[0], op[1], op[2], op[3]); // v[0]은 접근할 필요 없으므로, index 1부터 시작.
	cout << max_num << endl << min_num;
}
