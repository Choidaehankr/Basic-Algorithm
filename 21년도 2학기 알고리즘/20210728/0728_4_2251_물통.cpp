#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int A_size, B_size, C_size;
bool visit[200][200][200];
vector<int> v;

//BFS 탐색을 하며 A, B, C 물통의 크기와 물통 안에 들어있는 물의 잔여량을 파악해서 계산해주고 A가 비어있을 때, C의 상태를 저장한다.

// 1. (붓는 물통의 양 + 받는 물통의 양 > 받는 물통 크기)일 경우, 붓는 물통은 완전히 비지 않는다.
// 2. (붓는 물통의 양 + 받는 물통의 양 <= 받는 물통의 크기). 붓는 물통은 완전히 빈다 (0).

void BFS() {
	queue<pair<pair<int, int>, int>> q; // {{A, B}, C}
	q.push({ { 0,0 }, C_size }); // A와 B는 비어있는 상태로 시작.
	while (!q.empty()) {
		int a = q.front().first.first;
		int b = q.front().first.second;
		int c = q.front().second;
		q.pop();

		if (visit[a][b][c]) continue; //방문했을 경우

		visit[a][b][c] = true;

		if (a == 0) { //물통 a가 비어있을 때 c의 상태를 파악하는 것이 목적!
			v.push_back(c);
		}

		// c에서 a로 붓는 경우
		if (c + a > A_size) { // A는 가득차게 되고, C에는 잔여량이 존재.
			q.push(make_pair(make_pair(A_size, b), c + a - A_size)); 
			// 물통 c와 a에 들어있는 물의 양이 A의 크기보다 클 경우, A는 가득차게 되므로 A_size를 push, C에는 잔여량 c + a - A_size를 push
		}
		else {
			q.push(make_pair(make_pair(c + a, b), 0));
		}

		// c에서 b로 붓는 경우
		if (c + b > B_size) { // B는 가득차게 되고, C에 잔여량 존재.
			q.push(make_pair(make_pair(a, B_size), c + b - B_size));
		}
		else {
			q.push(make_pair(make_pair(a, c + b), 0));
		}

		//a에서 b로 붓는 경우
		if (a + b > B_size)
			q.push(make_pair(make_pair(a + b - B_size, B_size), c));
		else
			q.push(make_pair(make_pair(0, a + b), c));

		//a에서 c로 붓는 경우
		if (a + c > C_size)
			q.push(make_pair(make_pair(a + c - C_size, b), C_size)); // a+b-C_size??
		else
			q.push(make_pair(make_pair(0, b), a + c));

		//b에서 a로
		if (b + a > A_size)
			q.push(make_pair(make_pair(A_size, b + a - A_size), c));
		else
			q.push(make_pair(make_pair(b + a, 0), c));

		//b에서 c로
		if (b + c > C_size)
			q.push(make_pair(make_pair(a, b + c - C_size), C_size));
		else
			q.push(make_pair(make_pair(a, 0), b + c));
	}
}

int main() {
	cin >> A_size >> B_size >> C_size;
	BFS();
	sort(v.begin(), v.end());	
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}
}