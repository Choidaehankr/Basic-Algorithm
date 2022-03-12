#include <iostream>
using namespace std;
int arr[100];
int N;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int cnt = 0;
	//풀이: 배열의 뒤에서 (N번쨰) 부터 접근하며 N-1이 N보다 작을때 까지 arr[N-1]을 1씩 감소시키며 카운트해준다.
	for (int i = N-1; i >= 1; i--) {
		if (arr[i] <= arr[i - 1]) {
			while (arr[i] <= arr[i - 1]) {
				cnt++;
				arr[i - 1] -= 1;
			}
		}
	}
	cout << cnt;
}
