#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
string solution(string new_id) {
	string answer = "";
	queue <char> q;
	//char형 queue선언해서 new_id의 문자를 모두 push해준다.
	for (int i = 0; i < new_id.length(); i++) {
		q.push(new_id[i]);
	}
	int i = 0; // i는 현재 answer의 크기를 나타낼 것임.
	char tmp = ' '; //tmp는 '.'의 중복을 확인하기 위함

	//q를 모두 탐색한다.. q가 빌때까지 모든 검사를 마치고, 적절하다면 answer에 대입해준다.
	while (!q.empty()) {
		char ch = q.front();
		if (i >= 15) { // answer의 길이가 15를 초과했다면 종료
			break;
		}
		if (ch >= 'A' && ch <= 'Z') { //대문자를 소문자로 치환
			answer += ch + 32;
			q.pop(); i++;
		}
		else if (i == 0 && ch == '.') {
			q.pop(); // 첫번째 문자가 '.'일 경우. i는 증가하지 않음
		} 
		else if (tmp == '.' && ch == '.') { // '.'의 중복 방지를 위해 tmp변수 사용
			q.pop();
		}
		else {
			if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || ch == '-' || ch == '_' || ch == '.') {
				answer += ch; //사용 가능한 문자라면 answer에 대입
				i++;
			}
			q.pop();
		}
		tmp = ch;
	}
	if (answer == "") //빈 문자열일 경우
		answer += 'a';
	//마지막 문자가 '.'이거나, answer의 길이가 3이하인 경우
	while (1) {
		if (answer.back() == '.') { 
			answer.pop_back();
		}
		char ch = answer.back();
		if (ch != '.' && answer.length() < 3) {
			answer.push_back(ch);
		}
		if (answer.length() >= 3 && answer.back() != '.')
			break;
	}
	return answer;
}

// 1시간 30분 소요
//88.5점. 20, 21, 25번 틀림. 
//네 네

int main() {
	string new_id;
	cin >> new_id;
	cout << solution(new_id);
}