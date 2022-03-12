#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N; cin >> N;
	vector <int> v;
	long long int result = 0; //자료형 주의
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		v.push_back(num);
	}
	// 예상 등수대로 오름차순 정렬. 실제 등수(?)에서 빼준 뒤 절댓값을 취한 값을 result에 더한다.
	sort(v.begin(), v.end()); 
	for (int i = 0; i < v.size(); i++) {
		result += abs((i+1) - v[i]); 
	}
	cout << result;
}