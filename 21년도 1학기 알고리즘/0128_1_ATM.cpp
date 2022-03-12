#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector <int> v;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end()); //오름차순 정렬을 통해 최종 값을 최소화함
	int sum = 0;
	int realsum = 0;
	for (auto it = v.begin(); it != v.end(); it++) {
		sum += *it; // iterator로 접근하는 원소들을 더해줌
		realsum += sum; // 최종 값을 구하기 위해 sum에 담긴 값들을 계속 더해줌
	}
	cout << realsum;
}