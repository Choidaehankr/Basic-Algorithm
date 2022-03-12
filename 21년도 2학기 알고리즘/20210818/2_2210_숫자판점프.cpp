#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[5][5];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1 , 0, 0 };
bool visit[1000000]; // 중복 방지를 위한 1000000 까지를 담을 수 있는 visit 선언
vector<int> v;
void solve(int x, int y, int num, int cnt) {
	if (cnt == 6) { //6번 탐색을 마치고
		if (!visit[num]) { //이미 나온 숫자가 아닐 경우 (중복 X), 실행
			visit[num] = true;
			v.push_back(num);
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5)
			continue;
		solve(nx, ny, num * 10 + arr[nx][ny], cnt + 1); // 숫자를 이어붙이기 위한 'num * 10 + arr[nx][ny]'
	}
}
int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			solve(i, j, 0, 0); //모든 좌표를 dfs 탐색
		}
	}
	cout << v.size();
}