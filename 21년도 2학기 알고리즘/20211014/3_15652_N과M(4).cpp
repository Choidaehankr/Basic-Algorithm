#include <iostream>
using namespace std;

#define MAX 7
int N, M;
int arr[MAX];
int cnt = 1;
void backTracking(int idx) {
	cout << "backTracking called count is " << cnt++ << endl;
	if (idx == M) {
		for (int i = 0; i < M; i++) {
			cout << "arr[" << i << "] is " << arr[i] << " ";
		}
		cout << '\n';

		return;
	}
	for (int i = 1; i <= N; i++) {
		arr[idx] = i;
		cout << "2nd for-loop called is " << cnt++ << endl;
		backTracking(idx + 1);
	}
}

int main() {
	cout << "input number plz ";
	cin >> N >> M;
	backTracking(0);
	return 0;
}
