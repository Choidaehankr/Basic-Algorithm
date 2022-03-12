#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string board;
	string result = "";
	string A = "AAAA", B = "BB";
	vector <int> v;
	cin >> board;
	int cnt = 0;

	for (int i = 0; i < board.size(); i++) {
		int c = board[i];
		if (c == 'X') {
			cnt++; //X의 개수를 세서 vector v에 넣어줌!
		}
		else {
			if (cnt != 0) {
				v.push_back(cnt); //cnt가 0이 아니고 '.'을 만났다면 '.'을 만나기 전 cnt 개수를 push
			}
			v.push_back(-1); // '.'을 만나면 -1을 넣어줌
			cnt = 0;
		}
	}

	v.push_back(cnt);

	for (int i = 0; i < v.size(); i++) {
		if (v[i] == -1) { // '.'일 경우
			result += '.';
			continue;
		}
		while (v[i] != 0) { //while 문을 돌면서 'AAAA'가 들어갈 수 있으면 냅다 집어넣고, 그게 아니라면 'BB'를 넣어줌
			if (v[i] >= 4) {
				v[i] -= 4;
				result += A;
			}
			else if (v[i] >= 2) {
				v[i] -= 2;
				result += B;
			}
			else if (v[i] % 2 != 0) { //2로 나누어 떨어지지 않을 경우, 조건을 만족하지 않으므로 -1 출력후 종료
				cout << -1 << endl;
				return 0;
			}
		}
	}
	cout << result;
}