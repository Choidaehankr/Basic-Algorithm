//int형 arr배열에 숫자를 입력받고 ans배열에 찾을 값을 넣는다.
//답 출력을 위한 배열 check[]를 ans 사이즈 만큼 선언
//sort함수로 arr배열을 정렬하고 numCount 함수로 ans배열을 이진탐색한다
//pt 변수로 탐색할 위치를 지정
//찾는 값 num (ans[i]) 이 arr[pt] 보다 작을 경우 탐색 범위를 start ~ pt -1,
//크다면  pt + 1 ~ end 로 설정
//값을 찾았다면 check[i]를 ++
//마지막 for문으로 check[i]를 출력

#pragma warning(disable : 4996)	
#include <iostream>
#include <algorithm>
using namespace std;
int* arr, * ans, * check;

int numCard(int start, int end, int num) {
	int pt = (start + end) / 2;
	int result;
	int cnt = 0;
	if (start > end) {
		return cnt;
	}
	else {
		if (arr[pt] > num) {
			return numCard(start, pt - 1, num);
		}
		else if (arr[pt] < num) {
			return numCard(pt + 1, end, num);
		}
		else {
			return numCard(pt + 1, end, num);
			check[pt] += 1;
		}
	}
	return cnt;
}

////////////////////////////////////////////////////////

#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int* arr, * ans;
int N, M;

int main() {
	scanf("%d", &N);
	arr = new int[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	scanf("%d", &M);
	int num;
	int cnt = 0;
	for (int i = 0; i < M; i++) {
		scanf("%d", &num);
		for (int i = 0; i < M; i++) {
			if (num == arr[i])
				cnt++;
		}
		cout << cnt << ' ';
		cnt = 0;
	}
}
