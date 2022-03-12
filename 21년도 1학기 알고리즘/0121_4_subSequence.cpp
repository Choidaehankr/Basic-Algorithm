#include <iostream>
using namespace std;
int arr[20];
int n, s;
int cnt = 0;
void subSequence(int index, int sum) {
	sum += arr[index];
	if (index >= n) //index가 n이상이면 base case
		return;
	if (sum == s) //sum과 s가 같다면 cnt++
		cnt++;
	subSequence(index + 1, sum - arr[index]); //sum에 arr[index]를 추가하지 않은 경우
	subSequence(index + 1, sum); //sum에 arr[index]를 추가한 경우
}

int main() {
	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr[i] = num;
	}
	subSequence(0, 0);
	cout << cnt;
}


