#pragma warning (disable:4996)
#include <iostream>
#include <algorithm>
using namespace std;

int arr[501][501];
int res[501][501] = { 0, };

//밑에서 부터 인접한 요소에 접근하는 방법으로 하다가 계속 실패
//그냥 위에서 부터 내려감

// *핵심: c[i, j] = m_ij + max(c[i-1, j], c[i, j-1]);

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	res[1][1] = arr[1][1];
	//접근 가능한 요소 중 현재 위치에서 더했을때 최댓값이 되는 경우를
	//res배열에 기록
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			res[i][j] = max(res[i - 1][j - 1], res[i - 1][j]) + arr[i][j]; 
		}
	}
	int max = 0;
	//마지막 열에서 최대값을 탐색
	for (int i = 0; i <= n; i++) {
		if (max < res[n][i])
			max = res[n][i];
	}
	cout << max;
}