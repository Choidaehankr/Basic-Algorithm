#include <iostream>
#include <algorithm>
#define MAX 51

using namespace std;
int N;
char arr[MAX][MAX];
int maxColor = 0;

// 모든 원소를 접근하며 swap함수로 인접한 사탕의 위치를 바꿈
// check하는 함수를 호출하여 사탕의 위치를 바꿨을 때마다 사탕의 최대 연속 길이를 구함

void maxLengthCheck() {
	char prev_c;
	for (int i = 0; i < N; i++) {		//각 행을 탐색하며 최대로 이어진 사탕 찾기
		int cnt = 1;
		prev_c = arr[i][0];
		for (int j = 1; j < N; j++) {
			if (prev_c != arr[i][j]) { // 사탕이 끊길경우 cnt를 1로 초기화
				cnt = 1;
			}
			else {
				cnt++;
			}
		prev_c = arr[i][j];
		maxColor = max(maxColor, cnt);		//동일한 사탕의 최대 연속 길이 갱신
		}
	}
	for (int i = 0; i < N; i++) {
		int cnt = 1;
		char prev_c = arr[0][i];
		for (int j = 1; j < N; j++) {
			if (prev_c != arr[j][i]) {
				cnt = 1;
			}
			else {
				cnt++;
			}
			prev_c = arr[j][i];
			maxColor = max(maxColor, cnt);
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < N; i++) { // 행 탐색
		for (int j = 0; j < N; j++) {
			swap(arr[i][j], arr[i][j + 1]); // swap함수를 이용해서 인접한 행의 원소를 바꿔줌
			maxLengthCheck();
			swap(arr[i][j], arr[i][j + 1]); // 바꾼거 원위치
		}
	}
	for (int i = 0; i < N; i++) { // 열 탐색
		for (int j = 0; j < N; j++) {
			swap(arr[i][j], arr[i + 1][j]);
			maxLengthCheck();
			swap(arr[i][j], arr[i + 1][j]);
		}
	}
	cout << maxColor;
}