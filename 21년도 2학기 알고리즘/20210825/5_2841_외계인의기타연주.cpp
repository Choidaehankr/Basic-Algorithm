#include <iostream>
#include <stack>
#include <queue>
using namespace std;
queue<pair<int, int>> q;
stack<int> st[7];
int N, P;
int main() {
	cin >> N >> P;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int line, fret;
		cin >> line >> fret;
		//해당 line 스택이 비어있을 때 바로 추가해줌.
		if (st[line].empty()) {
			st[line].push(fret);
			cnt++;
		}
		else { //해당 line 스택이 비어있지 않고,
			if (st[line].top() < fret) { //입력받은 fret이 기존의 fret보다 높다면 스택에 추가.
				cnt++;
				st[line].push(fret);
			}
			else { //입력받은 fret이 기존의 fret보다 작다면
				while (!st[line].empty() && fret < st[line].top()) { //입력받은 fret이 스택에 있는 fret보다 높거나 
					//같거나, 스택이 빌 때까지 pop()
					st[line].pop();
					cnt++;
				}
			if (!st[line].empty() && st[line].top() == fret) //fret이 이미 있다면 continue
				continue;
			st[line].push(fret);
			cnt++;
			}
		}
	}
	cout << cnt;
}