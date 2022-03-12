#include <iostream>
using namespace std;
int main() {
	int N[11];
	int n, s, r; cin >> n >> s >> r;
	//n: 팀의 수, s: 카약이 손상된 팀, r: 카약을 하나 더 가져온 팀
	int result = 0;
	for (int i = 1; i <= n; i++) {
		N[i] = 1; //초반 모든 팀의 카약 수를 1로 초기화
	}
	for (int i = 1; i <= s; i++) {
		int num;
		cin >> num; // 카약이 고장난 팀은 카약 개수를 감소 (0이 되겠죠)
		N[num]--;
	}
	for (int i = 1; i <= r; i++) {
		int num; cin >> num; // 여유분의 카약을 가지고 있는 팀은 카약 개수를 ++
		N[num]++;
	}
	for (int i = 1; i <= n; i++) {
		if (i > 1) { // 1번째 팀은 이전 팀이 없으므로 인덱스를 1 기준으로 앞, 뒤로 나눠 계산
			if (N[i] < 1) { //i번째 팀이 보유한 카약 수가 1개 이하일 경우.
				if (N[i - 1] > 1) {
					N[i]++; N[i - 1]--; //앞의 팀이 여유분의 카약이 있을 경우
				}
				else if (N[i + 1] > 1) {
					N[i]++; N[i + 1]--; //뒤의 팀이 여유분의 카약이 있을 경우
				}
			}
		}
		//1번째 팀의 경우
		else {
			if (N[i] < 1) { 
				if (N[i + 1] > 1) {
					N[i + 1]--; //뒤의 팀만 접근
					N[i]++;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (N[i] < 1) {
			result++; //보유한 카약 개수가 1이하일 경우 참가할 수 없음.
		}
	}
	cout << result;
}