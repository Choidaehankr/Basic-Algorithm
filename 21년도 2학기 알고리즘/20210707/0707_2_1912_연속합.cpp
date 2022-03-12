//n개의 정수로 이루어진 임의의 수열이 주어진다.우리는 이 중 연속된 몇 개의 수를 선택해서 구할 수 있는 
//합 중 가장 큰 합을 구하려고 한다.단, 수는 한 개 이상 선택해야 한다.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 100000
int arr[MAX] = {};
int dp[MAX] = {};
int n, result; 

//i번째 직전까지의 최대합과, 그냥 자기 자신값 비교
//각 원소까지의 최대합을 dp[]에 넣어놓음. 계속 dp안의 값을 비교하며 result 변수에 넣어둠

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		arr[i] = num;
	}
	result = dp[0] = arr[0]; //result와 dp[0]에 처음값 arr[0]을 넣어줘야 함.

	for (int i = 0; i < n; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]); //dp[i]에는 연속합의 최대값을 찾기 위해 '이전 dp테이블에 있는 값과 arr[i]에 들어있는 값의 합' 과 이전 값을 
												//더하지 않은 그냥 arr[i]값의 크기를 비교.
		result = max(result, dp[i]); // 최종값 result에는 이전까지 누적된 result와 dp테이블에 업데이트 된 값 중 최대값을 저장
	}
	cout << result << endl;
}