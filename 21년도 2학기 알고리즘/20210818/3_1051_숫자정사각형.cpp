#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int arr[50][50];
int N, M;
string board[50];
int solve() {
	int result = 1; //기본 크기 1

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 1; k < min(N, M); k++) {
				if (i + k < N && j + k < M) { //배열의 범위 내에 있어야하고, k의 값을 1부터 늘려가며 최대 범위를 찾음.
					//삼각형을 찾기 위해서는 위치 '[i][j]'를 기준으로 [i][j+k], [i+k][j], [i+k][j+k]가 필요함!
					if((arr[i + k][j] == arr[i][j]) && (arr[i + k][j + k] == arr[i][j]) && (arr[i][j + k] == arr[i][j]))
						result = max(result, k + 1);
				}
			}
		}
	}
	return pow(result, 2);
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			arr[i][j] = (board[i].at(j))-48; //arr에 정수로 값이 들어감.
		}
	} 
	cout << solve() << endl;
}