#include <iostream>
#include <stack>
#include <string>
using namespace std;
// '(' 다음 바로 ')'가 나오면 레이저. (19 줄)
// 나머지는 모두 막대기 개수.
// 레이저가 나올 경우 누적 막대기 개수 만큼 결과값 더해줌.
// ')'가 나올 경우 막대기의 끝이므로 stick을 감소시키고 결과를 증가 (레이저로 잘린 뒤 남은 부분이므로)
int main() {
	string str;
	cin >> str;
	
	int stick = 0, result = 0;
	char preStick;

	for (int i = 0; i < str.length(); i++) {
		if (str.at(i) == '(') //막대기 시작
			stick++;
		else {
			stick--;
			if (str.at(i - 1) == '(') //레이저
				result += stick; // 누적 막대기 개수만큼 result증가
			else // 레이저가 아닌 ')' 즉, 막대기 끝일 경우
				result++; //잘린 뒤 남은 부분 (1만큼) 증가)
		}
	}
	cout << result;
}