#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int>> v;
int N, result = 0;
int dp[16];

//무조건 i일에 상담을 해야하는 것이 아님. i일에 일을 했을 경우와 안했을 경우 비교가 필요
//sum에는 받을 예정의 금액들이 들어가므로 result와 sum 중 최댓값을 계속 비교해줘야함.

void solve(int day, int sum) {
	if (day > N) // basecase
		return;
	result = sum > result ? sum : result;
	for (int i = day; i < N; i++) {
		solve(i + v[i].first, sum + v[i].second); 
		//main문에서 접근을 시작한 날부터 N일째까지 받을 수 있는 금액을 전체 탐색
	}
}

int main() {
	int sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int T, P;
		cin >> T >> P;
		v.push_back({ T, P });
		//상담이 걸리는 시간 T와, 받을 금액 P를 pair로 묶음.
	}
	for (int i = 0; i < N; i++) {
		solve(i + v[i].first, v[i].second);
		//배열의 첫번째 원소부터 접근
	}
	cout << result << endl;
}