#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	int rest = K;
	int coin = 0;
	int result = 0;
	while (1) {
		if (rest == 0) // 입력된 K로 시작된 rest가 0. 즉, 남김없이 동전으로 바꿨으면 종료
			break;
		for (int i = N-1; i >= 0; i--) { //큰 동전부터 접근
			if ( rest >= v[i]) { // rest가 벡터 v[i]보다 크거나 같을경우.
				coin = v[i]; // coin이라는 변수에 동전 v[i]를 대입.
				break; //반복문 탈출하고 밑에 while문으로
			}
		}
		while (rest >= coin) { //rest가 동전보다 크거나 같을 때 까지. 
			rest -= coin; //rest에서 coin을 빼주고
			result++; //뺀 숫자만큼의 동전을 소비했다는 뜻이므로 result++
		}
		//그리고 다시 위의 for문 혹은 base case로.
	}
	cout << result;
}