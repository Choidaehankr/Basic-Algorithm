#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// 가장 높은 기둥을 max_num에 담는다.
	// 기둥을 담은 v를 위치를 기준으로 정렬.

	// 왼쪽에서부터 시작해서 현재 기둥보다 크거나 같은 기둥을 찾고, 찾는다면 answer에 현재 까지 넓이를 넣어주고 기준 잡은 기둥을 갱신해줌.
	// 오른쪽도 마찬가지로 진행
	// 가장 큰 기둥을 만나면 더 이상 answer의 값이 늘어나지 않음.

	int N; cin >> N;
	vector<pair <int, int>> v;
	int max_num = 0;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
		max_num = max(max_num, y);
	}

	sort(v.begin(), v.end());

	int leftWidth = v[0].first;
	int leftHeight = v[0].second;
	int answer = 0;
	for (int i = 0; i < v.size(); i++) {
		if (leftHeight <= v[i].second) {
			answer += (v[i].first - leftWidth) * leftHeight;
			leftHeight = v[i].second;
			leftWidth = v[i].first;
		}
	}
	int rightWidth = v.back().first;
	int rightHeight = v.back().second;
	for (int i = v.size() - 1; i > -1; i--) {
		if (rightHeight < v[i].second) {
			answer += (rightWidth - v[i].first) * rightHeight;
			rightHeight = v[i].second;
			rightWidth = v[i].first;
		}
	}
	cout << answer + max_num << endl;
}