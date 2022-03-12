#pragma warning(disable:4996)
#include <iostream>
#include <string>
using namespace std;

int alphaCheck(string str) {
	string croatia[8] = { "c=", "c-", "dz=", "d-", "lj",
		"nj", "s=", "z=" };

	for (int i = 0; i < 8; i++) {
		int fIndex = str.find(croatia[i]); //문자열 str에 크로아티아 문자 존재 여부 검사

		if (fIndex != -1) { //크로아티아 문자를 찾았을 때 '하나의 문자'로 카운트하기 위해 
			str.replace(fIndex, croatia[i].length(), "X"); //"X"로 replace시킨다.
			// replace(int num, int len, string x) : num부터 len까지 문자를 x로 변경

			i--; // "c=c="와 같이 중복된 문자가 있을 경우를 대비해 i를 감소시켜 재검색을 위함
		}
	}
	return str.length(); //최종 str의 길이를 리턴함.
}


int main() {
	string str;
	cout << "문자를 입력하세요";
	cin >> str;
	cout << alphaCheck(str) << endl;
}