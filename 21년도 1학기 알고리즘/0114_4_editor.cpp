#pragma warning(disable:4996)
#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;
	int cursor = str.length(); //커서는 문자의 끝을 가리킴
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++) {
		string s; // 'L', 'D', 'B' 등을 문자열 S로 받음
		getline(cin, s, '\n'); //공백을 포함한 문자를 받기 위해 getline()
		char c = s[0]; //문자의 첫번째 글짜를 판별
			switch (c) {
			case 'L':
				if (cursor <= 0) //커서가 맨앞을 가리킨다면 무시
					break;
				cursor--; //커서를 왼쪽으로 1칸 이동
				break;
			case 'D':
				if (cursor >= str.length()) //커서가 맨뒤를 가리킨다면 무시
					break;
				cursor++; //커서 오른쪽 1칸 이동
				break;
			case 'B':
				if (cursor == 0) //커서가 맨앞이면 무시
					break;
				str.erase(--cursor, 1); //커서의 왼쪽문자를 삭제
				break;
			case 'P': 
				char ch = s.at(2); // "P x"와 같이 S의 2번째 문자 'x'를 판별
				string s1{ ch }; //char형인 ch를 string 형으로 변환
				str.insert(cursor++, s1); //s1을 커서 위치에 삽입하고 커서를 1증가
				break;
			}
	}
	cout << str;
}
//시간 초과 ㅜ