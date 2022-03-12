#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int cnt = 0; //count 횟수를 새기 위함
	int rest = 0; // count를 10으로 나눴을 때 나머지를 구함
	while (1) {
		cnt++;
		rest = 0; //반복문마다 rest를 0으로 초기화
		int num = cnt; //cnt에 간접 접근을 위해 num을 선언
		for (int i = num; i > 0; i /= 10) { // i를 10으로 나누고
			rest += i % 10; // rest에 i를 10으로 나눈 나머지들을 더함
		}
		if (cnt + rest == n) //cnt와 rest의 값(즉, cnt의 각 자리수의 합)이 같을 경우
			break; //탈출
	}
	cout << cnt;
}

//시간초과
