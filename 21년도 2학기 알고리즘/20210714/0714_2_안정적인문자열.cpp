#include <iostream>
#include <string>
using namespace std;
int cnt = 0;
int seq = 1;

int main() {
	while (1) {
		cnt = 0;
		string str; cin >> str;

		if (str.find('-') != -1) { //basecase
			break;
		}
		while (!str.empty()) { 
			if (str.find("{}") != -1) {  // 안정적인 괄호의 조건 2. "S가 안정적이라면, { S }도 안정적인 문자열이다." 을 이용
				auto idx = str.find("{}"); //주어진 문자열에서 안정적인 "{}"를 발견하면 제거
				str.erase(idx, 2);
			}
			else { //문자열의 첫번째 원소와 두번째 원소만 각각 '{' '}'인지 비교해서 바꿔주고 cnt값을 늘려주면 
					//16번째 줄 if문에서 안정적인 문자열을 제거하므로 잘 동작한다.
				if (str[0] != '{') {
					cnt++;
					str[0] = '{';
				}
				if (str[1] != '}') {
					cnt++;
					str[1] = '}'; //
				}
			}
		}
		cout << seq << '.' << ' ' << cnt << endl;
		seq++;
	}
}
