#include <iostream>
#include <string>	
using namespace std;

int main() {
	int n;
	cin >> n;
	string check = "666"; //종말 숫자
	int cnt = 1;
	int num = 0;
	while (1) {
		string s = to_string(cnt); //cnt를 문자열 s로 변환
		if (s.find(check) != -1) { //s에서 666을 찾았을 때
			num++; //num을 증가
		}
		if (num == n) { //num(666을 찾은 횟수)와 n이 일치하다면
			cout << s; // s를 출력
			break;
		}
		cnt++; //여기서 s는 cnt++에 의해 자연스레 작은수부터 나올것임
	}
}

