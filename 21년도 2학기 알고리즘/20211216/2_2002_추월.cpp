#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
	int N, cnt=0;
	vector<string> v;
	map<string, int> m;

	string str;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> str;
		m[str] = i;  // <차량번호, 들어온 순서> 형태로 map에 push
	}
	for (int i = 0; i < N; i++) {
		cin >> str;
		v.push_back(str);  // 터널에서 나온 순서대로 vector에 push
	}
	// 터널에서 나온 순서대로 확인하며, 현재 나온 차량이 그 다음 나올 차량보다 순번이 높다면
	// 추월했다는 의미이므로 cnt를 증가
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (m[v[i]] > m[v[j]]) {
				cnt += 1;
				break;
			}
		}
	}
	cout << cnt;
}