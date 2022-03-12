#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//main문에서 arr배열을 정렬
//찾는값 num을 for문으로 M번 입력받고 findNum()호출
//start가 end보다 커진다면 못 찾았으므로 0출력 후 종료
// arr에서 num을 찾으면 1을 출력 종료
// arr[pt]가 num 보다 작으면 큰 값을 찾아야하기 때문에 
// 탐색위치를 pt+1부터 end까지 조정
// 크다면 반대로.

int N, M;
void findNum(int* arr, int start, int end, int num) {
	int pt;
	if (start > end) {
		printf("0\n");
		return;
	}
	else {
		pt = (start + end) / 2;
		if (arr[pt] == num) {
			printf("1\n");
			return;
		}
		else if (arr[pt] < num)
			return findNum(arr, pt + 1, end, num);
		else {
			return findNum(arr, start, pt - 1, num);
		}
	}
}

int main() {
	scanf("%d", &N);
	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + N);

	scanf("%d", &M);
	int num;
	for (int i = 0; i < M; i++) {
		scanf("%d", &num);
		findNum(arr, 0, N - 1, num);
	}
}