#pragma warning(disable:4996)
#include <iostream>
using namespace std;
int zrCnt[40] = { 1, 0 };
int oneCnt[40] = { 0, 1 };

void fib(int n) {
	for (int i = 2; i <= n; i++) {
		zrCnt[i] = zrCnt[i - 2] + zrCnt[i - 1];
		oneCnt[i] = oneCnt[i - 2] + oneCnt[i - 1];
	}
}

//문제에서 힌트를 얻어 0과 1일때는 바로 출력
//나머지 경우에 0 과 1이 나오는 횟수도 점화식을 새우다보니
//피보나치 개념 그대로 zrCnt[i-1]+zrCnt[i-2]임을 알게됨

int main() {	
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int num;
		scanf("%d", &num);
		if (num == 0) {
			printf("1 0\n");
		}
		else if (num == 1) {
			printf("0 1\n");
		}
		else {
			fib(num);
			printf("%d %d\n", zrCnt[num], oneCnt[num]);
		}
	}
}