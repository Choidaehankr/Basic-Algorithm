#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> answer;
vector<string> solution(vector<string> record) {
    vector<pair<char, pair<string, string>>> users;
    for (int i = 0; i < record.size(); i++) {
        for (int j = 0; j < record[i].size(); j++) {
            char c = record[i].at(j);
            string userID = "", userName = "";
            int spaceNum = 0;
            if (c == 'E') {
                while (record[i].at(j) != ' ') {
                    j++;
                }
                j++;
                while (record[i].at(j) != ' ') {
                    userID += record[i].at(j); //userID가 들어감
                    j++;
                }
                j++;
                while (j < record[i].size()) {
                    userName += record[i].at(j);
                    j++;
                }
                users.push_back({ 'E', { userID, userName } });
            }
            else if (c == 'L') {
                while (record[i].at(j) != ' ') {
                    j++;
                }
                j++;
                while (j < record[i].size()) {
                    userID += record[i].at(j);
                    j++;
                }
                for (int k = 0; k < users.size(); k++) {
                    if (users[k].second.first.find(userID) != -1) {
                        userName = users[k].second.second;
                    }
                }
                users.push_back({ 'L', { userID, userName } });
            }
            else {
                while (record[i].at(j) != ' ') {
                    j++;
                }
                j++;
                while (record[i].at(j) != ' ') {
                    userID += record[i].at(j);
                    j++;
                }
                j++;
                while (j < record[i].size()) {
                    userName += record[i].at(j);
                    j++;
                }
                users.push_back({ 'C', {userID, userName} });
            }
        }
    }
    for (int i = users.size() - 1; i >= 0; i--) {
        string id = users[i].second.first;
        string name = users[i].second.second;
        for (int j = i - 1; j >= 0; j--) {
            if (users[i].first == 'C') {
                if (users[j].second.first.find(id) != -1) {
                    users[j].second.second = name;
                }
            }
            else if (users[i].first == 'E') {
                if (users[j].second.first.find(id) != -1) {
                    users[j].second.second = name;
                }
            }
        }
    }
    for (int i = 0; i < users.size(); i++) {
        if (users[i].first == 'E') {
            answer.push_back(users[i].second.second + "님이 들어왔습니다.");
        }
        else if (users[i].first == 'L') {
            answer.push_back(users[i].second.second + "님이 나갔습니다.");
        }
    }
    return answer;
}

int main() {
    vector<string> str;
    for (int i = 0; i < 5; i++) {
        string s;
        getline(cin, s);
        str.push_back(s);
    }
    solution(str);
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << endl;
    }
}

//(3시간.. + 1시간..) 33점.. 틀림 .. 죄송합니다..