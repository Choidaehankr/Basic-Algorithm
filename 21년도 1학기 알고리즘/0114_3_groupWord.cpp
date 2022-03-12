#pragma warning(disable:4996)
#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	int cnt = 0;		
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		int len = str.length();	
		int alphaCheck[26];
		fill_n(alphaCheck, 26, 0);
		bool state = true;
		for (int j = 0; j < len; j++) {
			char c = str.at(j);
			//각 알파벳 순서에 해당하는 배열을 체크
			if (alphaCheck[c - 'a'] == 0) { //알파벳이 처음 등장한다면
				alphaCheck[c - 'a'] = 1;  // '1' 로 만들어줌 state는 true로 유지
			}
			else { //알파벳이 이미 등장 했다면 (알파벳에 해당하는 배열이 0이 아니라면)
				if (c != str.at(j - 1)) { //c가 바로 직전 알파벳과 동일한지 검사
					state = false; //c가 이전 알파벳과 다르면 (반복되고 있는 단어가
					break;		   // 아니라면) 그룹단어가 아니므로 state = false
				}
			}
		}	
		if (state) //state가 true라면 그룹단어 이므로
			cnt++;
	}
	cout << cnt << endl;
}