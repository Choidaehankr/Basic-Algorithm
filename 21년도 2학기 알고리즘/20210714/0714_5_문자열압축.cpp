#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string s) {
    int answer = s.size(); 

    for (int i = 1; i <= (s.length() / 2); i++) { // 압축의 범위는 절반까지
        int cnt = 1;
        string str = s.substr(0, i); // 0번째 문자 부터 i까지 압축 가능한지 확인하는 문자열
        string comp, temp; 
        for (int j = i; j < s.length(); j += i) {
            comp = s.substr(j, i); //comp는 str과 비교할 문자열
            if (str == comp) {
                cnt++; //str과 comp가 같으면 cnt++. 계수를 의미
            }
            else {
                if (cnt > 1) {
                    temp += to_string(cnt); //계수(숫자)를 문자열로 변환
                }
                temp += str; // 압축 가능한 문자를 temp에 대입
                str = comp; // 비교 대상을 초기화
                cnt = 1;
            }
        }
        if (cnt > 1) {
            temp += to_string(cnt);
        }
        temp += str; //마지막 확인

        answer = answer < temp.size() ? answer : temp.size(); // min(answer, temp.size())가 안되길래 일케했습니다.
    }
    return answer;
}