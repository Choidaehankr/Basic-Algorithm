#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	int N; cin >> N;
	priority_queue<int, vector<int>, less<int>> q; //내림차순 정렬
	int size, sum, total = 0;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		q.push(num); 
	}
	// size = q.pop(); // 가장 큰 슬라임 저장. 이후 q.pop();
	//sum에는 슬라임의 크기를 곱하여 점수를 넣음. total에는 누적 점수. size는 크기!
	for (int i = 0; i < N-1; i++) {
		sum = size * q.top();
		total += sum;
		// size += q.pop();
		q.pop();
	}
	cout << total;
}