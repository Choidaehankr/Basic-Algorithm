#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

bool check(string s) { // 올바른 괄호 문자열인지 확인하는 함수.
    stack<int> st;
    int openCnt = 0, closeCnt = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(s[i]);
            openCnt++;
        }
        if (s[i] == ')') {
            closeCnt++;
            if (!st.empty())
                st.pop();
        }
    }
    if (st.empty() && openCnt == closeCnt && openCnt > 0 && closeCnt > 0)
        return true;
    else return false;
}

string solution(string p) {
    string answer = "";
    string u, v;

    if (check(p)) return p; // 0. p가 올바른 문자열이라면 그대로 return

    if (p == "") return ""; // 1. p가 빈 문자열일 경우 ""를 return

    int open = 0, close = 0;
    int num;
    for (int i = 0; i < p.length(); i++) { // 2. u와 v 분리
        //u가 균형잡힌 괄호 문자열일 경우 v에 대입
        if (open >= 1 && close >= 1 && open == close) {
            v += p[i];
            continue;
        }
        //u를 균형잡힌 괄호 문자열을 만들기 위한 코드
        if (p[i] == '(') {
            u += p[i];
            open++;
        }
        else {
            u += p[i];
            close++;
        }
    }
    // 3. u가 올바를 경우 문자열 v에 대해 1단계부터 수행. 이후 결과를 u에 이어 붙임
    if (check(u)) {
        return u += solution(v);
    }
    // 4. u가 올바르지 않을 경우. 
    //  4-1.빈문자열 answer에 '(' 붙인다. 4-2. 문자열 v에 대해 1단계 부터 수행한 결과를 붙이고, 4-3. ')'를 붙인다
    //  4-4. 처음과 마지막 문자를 제거. 문자열 괄호 방향을 뒤집는다.
    else {
        answer += '(' + solution(v) + ')';
        u.erase(0, 1); 
        u.pop_back();
        for (int i = 0; i < u.length(); i++) {
            if (u[i] == '(')
                answer.push_back(')');
            else
                answer.push_back('(');
        }
    }
    return answer;
}

// 1시간 05분 소요

int main() {
    string str;
    cin >> str;
    cout << solution(str);
}