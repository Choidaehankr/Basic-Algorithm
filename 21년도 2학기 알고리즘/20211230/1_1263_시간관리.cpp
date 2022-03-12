#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 역순으로 접근해서 일을 시작해도 되는 가장 늦은 시각 ans를 찾는다.
// (1, 16) (5, 20)일때, (20-5) = 15, (15-1) = 14로, 14시에 일을 시작하면 두 일을 끝낼 수 있음.
// 하지만 (3, 5), (8, 14)일 때, 
// (14-8) = 6, 6시에 일을 시작해도 되지만 다음 일은 5시까지 끝내야 하므로 (5-3) = 2가 답이 됨.


int main() {
	int N;
	cin >> N;
	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++) {
		int T, S;
		cin >> T >> S;
		v.push_back({ T, S });
	}

	sort(v.begin(), v.end(),  // 마감 기한이 늦는 순서대로 정렬
		[](auto& x, auto& y) {return x.second > y.second; });

	int ans = v[0].second - v[0].first;  // 마지막 일을 시작해야하는 시간 (15시)


	for (int i = 1; i < N; i++) {
		if (ans > v[i].second) {  // ans가 다음 일을 끝내야하는 시간보다 작다면,
			ans = v[i].second - v[i].first;  // 일을 시작해야하는 가장 늦은 시간
		}
		else {  
			ans -= v[i].first; 
		}
		if (ans < 0) {
			cout << -1 << endl;
			return 0;
		}
	}
	cout << ans;
}