#pragma warning (disable:4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int arr[25][25] = { 0, };
int visited[25][25] = { 0, };
int mX[4] = { 0, 0, 1, -1 }; //상하좌우 이동
int mY[4] = { 1, -1, 0, 0 };
int result = 0;
int N;
vector<int> v; //결과값 저장

void dfs(int x, int y) {
	result++; //dfs 탐색한만큼 결과값 증가
	visited[x][y] = 1; //방문했다고 표시
	for (int i = 0; i < 4; i++) {
		int numX = x + mX[i]; //상하좌우 모두 탐색
		int numY = y + mY[i];
		if (numX < 0 || numY < 0 || numX >= N || numY >= N) //배열 범위 밖으로 벗어난다면 continue
			continue;
		if (arr[numX][numY] == 1 && visited[numX][numY] == 0) //배열에 집이 있고 아직 방문을 안했다면
			dfs(numX, numY); //dfs 탐색
	}
}

int main() {
	cin >> N;
	string str; //문자열로 받아서 하나하나 배열에 넣어줌.
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < N; j++) {
			arr[i][j] = str.at(j) - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 1 && visited[i][j] == 0) { //집이 있고 방문을 안했다면
				result = 0; //결과값 초기화
				dfs(i, j); //dfs탐색 시작
				v.push_back(result); //dfs함수를 거쳐 증가된 result값을 벡터 v에 push_back
			}
		}
	}
	sort(v.begin(), v.end()); //오름차순 정렬
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
}