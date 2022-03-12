#include <iostream>
#include <string>
#include <cstring>
#define MAX 21
using namespace std;

bool visited[MAX];

// 집합 내 원소 존재 여부를 위해 visited 배열을 선언
// all과 empty는 정수를 입력받지 않아도 됨. 
// endl 사용시, [ios_base::sync_with_stdio(0); cin.tie(0);] 미기입시 시간초과

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int M; cin >> M;
	for (int i = 0; i < M; i++) {
		string cmd;
		int num;
		cin >> cmd;
		if (cmd == "all") {
			memset(visited, true, sizeof(visited));
			continue;
		}
		else if (cmd == "empty") {
			memset(visited, false, sizeof(visited));
			continue;
		}
		cin >> num;
		if (cmd == "add") {
			visited[num] = true;
		}
		else if (cmd == "remove") {
			visited[num] = false;
		}
		else if (cmd == "toggle") {
			if (visited[num])
				visited[num] = false;
			else
				visited[num] = true;
		}
		else {
			if (visited[num])
				cout << 1 << '\n';
			else cout << 0 << '\n';
		}
	}
}