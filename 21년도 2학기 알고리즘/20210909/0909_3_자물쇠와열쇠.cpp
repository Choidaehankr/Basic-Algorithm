#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
using namespace std;
// 1. 일단 key를 회전 시킨 new_key를 받는다.
// 2. key의 돌기 부분이 lock의 돌기와 만나면 안된다  1
// 3. key를 회전 시킨 이후, 받은 new_key 배열에서 돌기인 부분만 찾는다
// -> if(new_key[i][j] == 1) -> vector.push_back(new_key[i][j]);
// 4. new_key의 돌기인 위치. 즉 i, j를 방문할 수 있는 lock의 모든 위치를 탐색하며

int dx[8] = { -1,-1,-1, 0, 0,1, 1, 1 };
int dy[8] = { -1,0,1,-1,1,-1, 0, 1 };
int n, m;
bool visit[20][20] = {};
vector<pair<int, int>> rotate(vector<vector<int>> graph) { //그래프 90도 회전 함수
    int m = graph.size();
    vector<vector<int>> newGraph(m, vector<int>(m, 0));
    vector<pair<int, int>> v;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            newGraph[i][j] = graph[m - j - 1][i];
            if (newGraph[i][j] == 1) //돌기라면 i,j 를 push
                v.push_back({ i, j });
        }
    }
    return v;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    vector<pair<int, int>> new_lock; //lock의 홈부분 좌표를 push
    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (lock[i][j] == 0)
                new_lock.push_back({ i, j }); 
        }
    }
    for (int k = 0; k < 4; k++) { // 시계방향 90도로 4번 돌거임
        vector<pair <int, int>> new_key = rotate(key); //key의 돌기 부분 저장
        for (int i = 0; i < new_key.size(); i++) {
            // key의 회전된 돌기부분 push
            q.push({ new_key[i].first, new_key[i].second });
        }
        vector<vector<int>> graph = lock; //lock 배열과 같은 배열 선언
        memset(visit, false, sizeof(visit));
        while (!q.empty()) {
            int nx = q.front().first;
            int ny = q.front().second;
            q.pop();
            visit[nx][ny] == true;
            for (int i = 0; i < 8; i++) {
                int mx = nx + dx[i];
                int my = ny + dy[i];
                if (mx < 0 || mx >= m || my < 0 || my >= m) continue;
                if (lock[mx][my] == 0 && !visit[mx][my]) { 
                    graph[mx][my] = 1; // 움직인 key의 mx, my (즉, 돌기가) lock의 mx, my가 홈이라면 graph를 1로 채워줌.
                }
            }
            // graph의 모든 인자가 채워졌는지 확인.
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < m; j++) {
                    if (graph[i][j] != 1)
                        answer = false;
                    else answer = true;
                }
            }
            if (answer)
                break;
        }
    }
    return answer;
}

int main() {
    vector<vector<int>> key;
    vector<vector<int>> lock;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        vector<int> v;
        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;
            v.push_back(num);
        }
        key.push_back(v);
    }
    for (int i = 0; i < m; i++) {
        vector<int> v;
        for (int j = 0; j < m; j++) {
            int num;
            cin >> num;
            v.push_back(num);
        }
        lock.push_back(v);
    }
    cout << solution(key, lock);
}

//2시간 2분... 73점.. 죄송합니다..