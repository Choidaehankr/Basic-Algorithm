#pragma warning (disable:4996)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int result; // 나무 설정 높이
int N, M;
int sum = 0; // 답 찾기 위한 변수


//나무 높이 (답)를 result 변수에 선언해서
//변수 sum에 각 나무를 result로 자른 값을 더해나가서 sum >= M이 된다면 종료

//또는 sum이 M보다 작다면 result 값을 줄여나가 다시 탐색하고

//이외에는 pivot 변수 설정으로 이진탐색을 해나가려고 함

void woodCutting(vector<int> v, int start, int end) {
	int pivot;
	if (sum >= M) {
		return;
	}
	else if (sum < M) {
		result--;
		return;
	}
	else {
		pivot = (start + end) / 2;
		if (v[pivot] < result) {
			sum += v[pivot] - result;
			return woodCutting(v, pivot + 1, end);
		}
		else if (v[pivot] >= result) {
			return woodCutting(v, start, pivot - 1);
		}
	}
}

/////////////////////////////////////////////////////////////

void woodCutting(vector<int> v, int start, int end) {
	int pt = (start + end) / 2;
	if (start > end)
		return;
	if (v[pt] > result) {
		for (int i = pt; i < N; i++) {
				if (v[i] > result) {
					sum += v[i] - result;
				}
			}
	}
	if (sum >= M)
		return;
	else {
		result--;
	}
}

int main() {
	scanf("%d %d", &N, &M);
	vector<int> v;
	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}
	sort(v.begin(), v.end());

	int start = 0, end = N - 1;
	int result = 0, sum = 0;
	woodCutting(v, 0, N - 1);
	cout << result;
}