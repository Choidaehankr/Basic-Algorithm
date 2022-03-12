#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		string func, num;
		int size;
		string str;
		vector<int> v;
		cin >> func; cin >> size; cin >> num;
		for (int i = 0; i < num.size(); i++) {
			if (num.at(i) >= '0' && num.at(i) <= '9') { //숫자 라면
				str += num.at(i);
			}
			else { // 숫자가 아닌 경우 (콤마, 괄호)
				if (str.length() != 0) { //str이 비어있지 않다면
					v.push_back(stoi(str)); //vector에 정수로 push_back
					str.clear(); //문자열 비워줌
				}
			}
		}
		bool reverse = false;
		bool check = false;

		int front = 0; int back = size; //문자열의 길이

		for (int i = 0; i < func.length(); i++) { //명령줄 검사
			if (func.at(i) == 'R') // 'R'이 존재할 경우
				reverse = !reverse; // reverse 의 상태를 바꿔준다.
			else {
				if (reverse == true) {
					back--; //back의 길이(문자열의 끝 지점)을 감소
				}
				else {
					front++; //시작 지점을 증가 ('D'일 경우 앞의 문자가 삭제 되므로)
				}
				if (front > back) { // front가 back 보다 커지면 안되므로 오류 설정 후 종료
					check = true;
					break;
				}
			}
		}
		if (check == true)
			cout << "error" << endl;
		else {
			printf("[");
			if (reverse == true) {
				for (int i = back - 1; i >= front; i--) {
					cout << v[i]; //문자열의 뒤에서 부터 출력
					if (i != front) //front를 만날때 까지 숫자 출력후 "," 출력
						printf(",");
				}
			}
			else { //안뒤집힌 경우
				for (int i = front; i < back; i++) {
					cout << v[i];
					if (i != back - 1) 
						printf(",");
				}
			}
			printf("]\n");
		}
	}
}