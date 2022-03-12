#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string A, B;
	cin >> A >> B;
	//그냥 문자열 A를 B크기 에 알맞게 다 끼워넣어 본다음. 차이가 가장 작은 부분에 넣고
	// 나머지 문자를 채워넣는다.

	// 채워줄 필요가 없었고, 그냥 주어진 문자열에서 A와 B가 얼마나 일치하는 지만 찾아내면 되는 문제였음.
	int cnt = 0;
	int result = A.size();
	for (int i = 0; i < B.length() - A.length() + 1; i++) {
		for (int j = 0; j < A.length(); j++) {
			if (A.at(j) != B.at(j + i)) {
				cnt++;
			}
		}
		result = min(result, cnt);
		cnt = 0;
	}
	cout << result;
}