#include <iostream>
#include <algorithm>
#include <string.h>
#define MAX 300
using namespace std;

int arr[MAX][MAX];
int tmp[MAX][MAX];
int N, M, R;
// 시간 초과
int main() {
	cin >> N >> M >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	int cnt = 1;
	int turn = N / 2;  // 배열 내부에서 총 N/2 번 회전이 이루어져야 함. EX) N/M이 4/4 라면 인덱스 0~3까지, 1~2까지 총 2번
	for (int z = 0; z < R; z++) {  // 배열을 R번 돌리기 위함.
		for (int k = 1; k <= turn; k++) {  //  turn번 돌리기 위함
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (j == k - 1 && i < N - k && i >= k - 1) { // 아래로 가는거
						tmp[i + 1][j] = arr[i][j];
					}
					else if (i == N - k && j < M - k && j >= k - 1) { // 오른쪽
						tmp[i][j + 1] = arr[i][j];
					}
					else if (i > k - 1 && i <= N - k && j == M - k) { // 위로
						tmp[i - 1][j] = arr[i][j];
					}
					else if (i == k - 1 && j > k - 1 && j <= M - k) {  // 왼쪽
						tmp[i][j - 1] = arr[i][j];
					}
				}
			}
		}
		memcpy(arr, tmp, sizeof(tmp));  // arr에 tmp에 있는 값을 복사하고 R번 돌리기 위해 다시 첫번째 for-loop로 감.
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
}