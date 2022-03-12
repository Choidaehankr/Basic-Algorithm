#include <iostream>
#include <algorithm>
using namespace std;

//파라메트릭 서치(Parametric Search)
//: '범위'내에서 원하는 조건에 부합하는 값 찾기
// <-> 이진 탐색: 주어진 '일련의 값'들 중 원하는 값 찾기

// ex: 배가 7시간 마다 고파지는 사람이 하루를 배부르게 지내기 위한 최소한의 식사 횟수는?
// + 잠자는 시간을 고려하지 않음, 0끼 ~ 10끼까지의 식사 가능

// 24시간을 식사횟수로 나눴을 때 7또는 7에 가장 가까운 값이 나오도록 하는 것.
// 1) 범위가 0부터 10까지 이므로 (0+10)/2 = 5를 중간값 설정
//	  24/5 == 4.8 이므로 원하는 값 7보다 작음. 나누는 값이 더 작아져야하므로 4.9를 범위의 최댓값으로 설정
// 2) 범위 [0 ~ 4.9]/2 = 2.4 (중간값) -> 24/2.4 = 10. 7보다 큼. 2.5를 최솟값 설정
// 3) 범위 [2.5 ~ 4.9] .. 반복
// -> 2.5-4.9(3.7) -> 2.4-3.6(3) -> 3.1-3.6(3.3) -> 3.4-3.6(3.5)
// -> [3.4-3.4(3.4)] -> 3.4-3.3(3.3)
// 시작값 >= 끝값 일 경우 탐색 종료. 이 직전의 값 3.4가 구하고자 하는 값.

float parametricSearch(float start, float end) {
	float mid, tempMid;
	while (start <= end) { //종료 조건
		mid = tempMid; //직전 값 저장위함
		tempMid = (start + end) / 2.0; //중간값 설정
		if (24 / tempMid > 7) {
			start = tempMid + 0.1; //7시간이 넘는경우 시작 값을 갱신
		}
		else if (24 / tempMid < 7) {
			end = tempMid - 0.1; //7시간 이하일 경우 끝 값을 갱신
		}
		else {
			break; //최적해를 찾는다면 break
		}
	}
	return mid;
}



int N, sum = 0;
int money[100001];

//m은 만족해야할 인출 횟수

int parametricSearch(int m, int start, int end) {
	int answer = 0;
	while (start <= end) {
		int num = (start + end) / 2; //초기에 100 + 1000 = 550
		int cnt = 0;
		bool state = false;
		int nMoney = 0;
		for (int i = 0; i < N; i++) {
			if (money[i] > num) { //새로 인출해야함.
				state = true;
				break;
			}
			if (money[i] > nMoney) { //접근한 돈이 nMoney보다 크면.
				nMoney = num;
				cnt++;
			}
			else if ((m - cnt) == (N - i)) {
				nMoney = num;
				cnt++;
			}
			nMoney -= money[i];
		}
		if (state) {
			start = num + 1;
		}
		else if (cnt == m) {
			answer = num;
			end = num - 1;
		}
		else if (cnt > m) {
			start = num + 1;
		}
		else {
			end = num - 1;
		}
	}
	return answer;
}

int main() {
	int M, minNum = 10000;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		money[i] = num;
		sum += num;
		minNum = min(minNum, num);
	}
	cout << parametricSearch(M, minNum, sum);
	//하루 사용할 금액중 가장 적은 금액(start)과 총 사용할 금액(end)을 인자로 줌
}