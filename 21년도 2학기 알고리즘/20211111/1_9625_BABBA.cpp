#include <iostream>
using namespace std;

long long int fibo_arr[46] = { 1, 0 };
// N이 2일때 부터 A의 개수가 피보나치 수열을 따름.
// B의 개수는 N+1 번째 피보나치 수 값임.

long long int fibo(int N) {
	if (N == 0 || N == 1) {
		return fibo_arr[N];
	}
	else if (fibo_arr[N] == 0) {
		fibo_arr[N] = fibo(N - 1) + fibo(N - 2);
	}
	return fibo_arr[N];
}

int main() {
	int N; cin >> N;
	long long int A_num = fibo(N);
	long long int B_num = fibo_arr[N - 1] + fibo_arr[N];  // N+1 번째 피보나치 수를 찾기 위함.
	cout << A_num << ' ' << B_num;
}