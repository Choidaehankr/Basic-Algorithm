#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

int main() {
	string num; int P; //첫번째 수를 문자열로 입력 받음.
	cin >> num >> P;
	vector<string> s; // 문자열 벡터 선언
	int result = -1;
	while (1) {
		if (result != -1) //종료 조건
			break;
		s.push_back(num); //문자열 num을 문자열 벡터 s에 push_back
		int sum = 0; // 정수형 sum 선언
		for (int i = 0; i < num.length(); i++) {
			sum += pow((num.at(i) - 48), P); //sum에 문자열 num의 '각 자리수 -48 (아스키 코드)'의 P제곱 후 sum에 누적해서 더함
		}
		string tmp = to_string(sum); //위에서 구한 sum을 다시 문자열로 변환해서 tmp 변수에 할당
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == tmp) {
				result = j; //하나의 값을 구할때마다 벡터의 모든 원소가 tmp와 같은지 검사 (반복되는지)
				break; // 반복되는 구간이 있다면 for문을 종료
			}
		}
		num = tmp; // 다시 문자열 vector에 넣기위해 num 을 tmp로 초기화
	}
	cout << result; // 반복이 시작되는 index. 즉, result를 출력
}