#include <iostream>
#include <algorithm>
using namespace std;

//#define MAX 200
int Belt[200]; //벨트의 내구도가 담긴 배열
bool Exist[200]; //벨트 위에 로봇이 존재하는지 파악하는 배열
int N, K;
int main() {
	cin >> N >> K;
	for (int i = 1; i <= 2*N; i++) {
		cin >> Belt[i];
	}
	int cnt = 0, result = 0;

	//로봇을 올리는 위치는 1, 내리는 위치는 N으로 고정.
	while (1) {
		int nBelt = Belt[2 * N]; //2N 번째 배열을 저장
		int nExits = Exist[2 * N];
		if (Exist[N]) //회전하기 전에 내리는 위치에 로봇이 있는 경우
			Exist[N] = false;

		for (int i = 2 * N; i > 1; i--) { // 회전
			Belt[i] = Belt[i - 1];
			Exist[i] = Exist[i - 1];
		}
		if (Exist[N])
			Exist[N] = false; //회전 한 후 내려가는 위치에 로봇이 있을 경우

		Belt[1] = nBelt; Exist[1] = nExits; // 2N번째 있던 로봇을 1번에 할당

		//가장 먼저 올라간 로봇부터, 회전 방향으로 이동할 수 있다면 이동, N에서 내리기 때문에
		for (int i = N - 1; i >= 1; i--) {
			if (Exist[i] && !Exist[i + 1] && Belt[i + 1] > 0) {
				swap(Exist[i], Exist[i + 1]); // 로봇 위치를 swap
				Belt[i + 1]--; //올릴 수 있는 위치의 내구도를 감소
				if (Belt[i + 1] == 0) cnt++; //내구도가 0이 될 경우 cnt 증가
			}
		}
		//올라가는 위치(1)에 로봇이 없고, 내구도가 0 이상이라면 로봇 올림
		if (!Exist[1] && Belt[1] > 0) {
			Exist[1] = true;
			Belt[1]--;
			if (Belt[1] == 0) cnt++;
		}
		result++;

		if (cnt >= K) {
			cout << result;
			break;
		}
	}
}