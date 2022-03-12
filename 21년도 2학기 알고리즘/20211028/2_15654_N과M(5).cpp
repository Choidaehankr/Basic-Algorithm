#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 8
using namespace std;

int M, N;
vector<int> v;
int arr[MAX];
bool visit[MAX]; //visit 배열을 선언해서 방문했는지 확인


void backTracking(int idx) {
	if (idx == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < v.size(); i++) {
		if (visit[i]) 
			continue;
		
		visit[i] = true;
		arr[idx] = v[i];
		backTracking(idx + 1);
		visit[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	v.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end()); //사전 순 출력을 위한 오름차순 정렬

	backTracking(0);
}