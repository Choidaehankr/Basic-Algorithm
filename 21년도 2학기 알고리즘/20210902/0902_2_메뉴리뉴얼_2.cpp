// 4시간 정도 고민
// 어떻게 해야할 지 감은 오는데, 구현이 어려움.
// 순열을 이용해 조합을 구현하고자 구글링해서 시도해봤지만, 순열을 사용하기가 미숙함
// 죄송합니다 ㅠㅠ

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool desc(int a, int b) {
    return a > b;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    //priority_queue<pair<int, string>> pq;
    vector<string> answer;
    //우선 orders에 있는 "메뉴 구성"중 메뉴 갯수를 을 course에 있는 숫자 만큼 포함한 모든 경우의 수를 구해야 함.
    // order에 접근해서 course의 수만큼 순열을 만든다. 
    //이후 순열이 들어있는 모든 원소를 가지고 course 원소에 find()하며, 찾을 경우 cnt를 증가.
    //order에 있는 course의 크기만한 순열이 등장한 횟수가 2가 넘는다면, answer에 push_back
    int num = 0;
    for (int i = 0; i < course.size(); i++) {
        for (int j = 0; j < orders.size(); j++) {
            vector<string> list;
            int cs = course[i];
            int os = orders[i].size();
            vector<bool> v(os - cs, false);
            v.insert(v.end(), cs, true);
            do {
                string tmp = "";
                for (int k = 0; k < os; k++) {
                    if (v[k]) tmp += orders[k];
                    list.push_back(tmp);
                }
                cout << "i is " << i << " j is " << j << " k is " << " tmp is " << tmp << endl;
            } while (next_permutation(v.begin(), v.end()));
        }
    }
    return answer;
}
int main() {
    vector<string> idx;
    vector<int> gist;
    int on; int cn;
    cin >> on; cin >> cn;
    for (int i = 0; i < on; i++) {
        string str; cin >> str;
        idx.push_back(str);
    }
    for (int i = 0; i < cn; i++) {
        int num; cin >> num;
        gist.push_back(num);
    }
    solution(idx, gist);
}