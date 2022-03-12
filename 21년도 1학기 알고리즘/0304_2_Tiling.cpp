#include <iostream>
using namespace std;

//n이 3일때 답이 3이고 4일때 5, 9일때 55인것을 보고
// 1번 문제 풀때 써놓은 피보나치 수열과 값이 일치한것을 발견함
// 그래서 피보나치 코드를 사용함

int arr[1000] = { 0, };
int tiling1(int n) {
	arr[0] = 1, arr[1] = 1;
	for (int i = 2; i <= n; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
	}
	return arr[n];
}
int tiling2(int n) {
	if (arr[n] != 0)
		return arr[n];
	else {
		if (n == 0 || n == 1) {
			arr[n] = 1;
		}
		else {
			arr[n] = (tiling2(n - 1) + tiling2(n - 2)) % 10007;
		}
		return arr[n];
	}
}
int main() {
	int num;
	cin >> num;
	cout << tiling1(num) << endl;
}