#include <iostream>
#include <algorithm>

using namespace std;

//틀렸다하면 long long int 로 바꾸기

#define MAX 300000

long long int N, M;
long long int arr[MAX];
long long int maxNum = 0;

long long int result = 0;
long long int mid = 0;

long long int solve(long long int start, long long int end) {
	while (start <= end) {
		long long int cnt = 0;
		mid = (start + end) / 2; // mid는 각 사람이 가져가는 최대 보석 수
		for (int i = 0; i < M; i++) {
			if (arr[i] % mid == 0) { // cnt = 몇명에게 나누어 지는지 확인
				cnt += arr[i] / mid; // arr[i]가 mid로 나누어 떨어지면, arr[i]/mid 명에게 나눠줄 수 있음.
			}
			else {
				cnt += (arr[i] / mid) + 1; // ex) arr[i] = 7, mid = 5라면 2명에게 나눠줄 수 있으므로 '+1'
			}
		}
		if (cnt <= N) { //보석을 못가져가는 사람이 있어도 되므로
			end = mid - 1; // 탐색 끝 값을 감소
			result = mid;
		}
		else { // 보석이 남는 경우. 더 많이 나눠줘야 하므로
			start = mid + 1;
		}
	}
	return result;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int num; cin >> num;
		arr[i] = num;
		maxNum += num;
	}
	cout << solve(1, maxNum);
}