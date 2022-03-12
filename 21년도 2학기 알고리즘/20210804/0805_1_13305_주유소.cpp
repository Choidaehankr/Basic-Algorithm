#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100000
int N;
long long int oil[MAX], length[MAX];
int main() {
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> length[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> oil[i];
	}
	long long int min_oil = 1000000000;
	long long int sum = 0;
	//맨 오른쪽 도시 (N번째 도시) 로 이동하기 위해서 length 배열에 있는 원소를 (각 도시 간의 길이)
	//N번째 도시까지 기름의 최솟값을 min_oil에 곱해서 sum에 누적시킨다.
	for (int i = 0; i < N-1; i++) {
		min_oil = min(min_oil, oil[i]);
		sum += min_oil * length[i];
	}
	cout << sum;
}