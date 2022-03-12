#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
using namespace std;

int answer = 0;

bool compare(string x, string y) { //두 문자열의 대소문자 구분 없이 동일한지 확인
    string tmp1, tmp2;
    for (int i = 0; i < x.size(); i++) {
        tmp1 += toupper(x[i]);
    }
    for (int i = 0; i < y.size(); i++) {
        tmp2 += toupper(y[i]);
    }
    if (tmp1 == tmp2) return true;
    else return false;
}

int solution(int cacheSize, vector<string> cities) {
    if (cacheSize == 0) {
        return cities.size() * 5;
    }
    vector<string> v;
    /*
    for (int i = 0; i < cities.size(); i++) {
        //int index = 0;
        bool flag = true;
        for (int j = 0; j < v.size(); i++) {
            if (compare(cities[i], v[j])) {
                string temp = cities[i];
                v.erase(v.begin() + j);
                v.push_back(temp);
                flag = false;
                answer += 1;
                break;
            }
        }
        if (flag) {
            if (cacheSize == v.size()) {
                v.erase(v.begin());
                v.push_back(cities[i]);
            }
            else {
                v.push_back(cities[i]);
            }
            answer += 5;
        }
    }
    */
    /*
    dq.push_back(cities[0]);
    for (int i = 1; i < cities.size(); i++) {
        string str = cities[i];
        bool state = false;
        //cout << i+1 << " 번쨰 str is " << str << endl;
        if (dq.size() >= 3) {
            for (int j = 0; j < cacheSize; j++) {
                //if (_stricmp(str.c_str(), dq[j].c_str()) == 0) {
                if (compare(str, dq[j])) {
                    dq.erase(dq.begin() + j);
                    dq.push_front(str);
                    state = true;
                    break;
                }
            }
        }
        else {
            for (int j = 0; j < dq.size(); j++) {
                if (compare(str, dq[j])) {
                    dq.erase(dq.begin() + j);
                    dq.push_front(str);
                    state = true;
                    break;
                }
            }
        }
        if (state) answer += 1;
        else {
            dq.push_front(str);
            answer += 5;
        }
    }
    */
    for (int i = 0; i < cities.size(); i++) {
        bool state = true;
        for (int j = 0; j < v.size(); j++) { //v에 뭔가 들어있어야만 실행.
            if (compare(v[j], cities[i])) { //두 문자열이 같다면, 즉 cities[i]가 캐시에서 발견됐다면
                string tmp = v[j];
                v.erase(v.begin() + j); //v에 있는 cities[i]를 지워준 후 새로 push_back
                v.push_back(tmp);
                state = false;
                answer += 1; //cache hit 이므로 answer는 1만 증가 후 break
                break;
            }
        }
        // 문자열이 같지 않다면, 
        if (state) {
            if (cacheSize >= v.size()) { //vector v는 cacheSize를 유지함
                v.erase(v.begin()); //가장 오래된 v.begin()을 지워주고
                v.push_back(cities[i]); //최근에 사용된 cities[i]를 push_back
            }
            else { //cacheSize에 미달된다면, 냅다 push_back
                v.push_back(cities[i]);
            }
            answer += 5;
        }
    }
    return answer;
}

int main() {
    int n;
    vector<string> v;
    cin >> n;
    for (int i = 0; i < 10; i++) {
        string str;
        cin >> str;
        v.push_back(str);
    }
    cout << "answer is " << solution(n, v);
}


// 2시간 50분...