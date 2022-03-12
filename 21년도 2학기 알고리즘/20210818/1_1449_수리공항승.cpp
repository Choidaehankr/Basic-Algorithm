#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];

int main() {
	int cnt = 1;
	int N, L;
	cin >> N >> L;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N); //오름차순 정렬을 해줘야함.

	int fst = arr[0]; //첫번째 새는 위치를 담을 변수

	for (int i = 1; i < N; i++) {
		if (arr[i] - fst + 1 > L) { //기본 공식: 물이 새는 i+1 번째와 i번째 차 + 1이 테이프의 길이보다 크다면, 테이프 개수 + 1
			cnt++;
			fst = arr[i]; //시작 위치를 arr[i]로 초기화.
		}
	}
	cout << cnt;
}