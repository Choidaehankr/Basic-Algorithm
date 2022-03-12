#include <iostream>
using namespace std;
long long int dp[101] = { 0, 1, 1, 1 };

//규칙을 찾아보니 4번째 부터 n번째 삼각형 변의 길이는 n-3 + n-2임을 발견!
//계속 틀렸다가 자료형을 long long int로 하니 바로 맞았습니다.

long long int solve(int n) {
	if (n <= 3) {
		return dp[n]; //3번째 삼각형 이하일 경우 바로 1을 return
	}
	for (int i = 4; i <= n; i++) {
		dp[i] = dp[i - 3] + dp[i - 2];
	}
	return dp[n];
}

int main() {
	int T;
	cin >> T;
	int result[101];
	for (int i = 0; i < T; i++) {
		int num; cin >> num;
		cout << solve(num) << endl;
	}
}