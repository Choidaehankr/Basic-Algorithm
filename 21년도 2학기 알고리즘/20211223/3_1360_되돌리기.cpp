#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<pair<string, int>> v;
int N;


string solution(int sec) {
	for (int i = v.size() - 1; i >= 0; i--) {
		if (sec > v[i].second)
			return v[i].first;
	}
	return "";
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string cmd, ch;
		int sec;
		cin >> cmd >> ch >> sec;
		if (cmd == "type") {  // 명령이 type일 경우
			string str;
			if (!v.empty()) {  // vector 맨 뒤에 있는 문자열에 ch를 추가해줌
				str = v.back().first + ch;
			}
			else {
				str = ch;  // vector가 비어있을 경우
			}
			v.push_back({ str, sec });  // vector에 새로 생긴 문자열과 시간을 추가
		}
		else {  // undo A B 일 경우 벡터의 뒤에서 부터 탐색하며 (B-A)초 이전의 값을 찾으면 됨.
			v.push_back({solution(sec - atoi(ch.c_str())), sec});  
			// solution함수로 찾은 벡터의 (B-A)초에 있는 문자열을 현재 시간으로 새로 벡터에 추가
		}
	}
	cout << v.back().first;
}