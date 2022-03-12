#include <iostream>
#include <stack>
#include <cmath>
#include <algorithm>
using namespace std;
stack<pair<int, int>> s;
int main() {
	int W, H, N, curDir, curDist;  // 가로, 세로, 상점 수
	cin >> W >> H;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int dir, dist;  
		cin >> dir >> dist;
		s.push({ dir, dist });
	}
	cin >> curDir >> curDist;  // DJ's location
	int result = 0;
	while (!s.empty()) {
		int dir = s.top().first;
		int dist = s.top().second;
		s.pop();
		if (curDir == 2) {  // South
			if (dir == curDir) {  
				result += abs(curDist - dist);
			}
			else if (dir == 3) {
				result += min((H - dist) + curDist, (W - curDist) + H + W + dist);
			}
			else if (dir == 4) {
				result += min((W - curDist) + (H - dist), (curDist + H + W + dist));
			}
			else if (dir == 1) {
				result += min((curDist + H + dist), (W - curDist + H + W - dist));
			}
		}
		else if (curDir == 1) {  // North
			if (dir == curDir) {
				result += abs(curDist - dist);
			}
			else if (dir == 3) {
				result += min((curDist + dist), W - curDist + H + W + H - dist);;
			}
			else if (dir == 4) {
				result += min((W - curDist + dist), (curDist + H + W + H - dist));
			}
			else if (dir == 2) {
				result += min((curDist + H + dist), (W - curDist + H + W - dist));
			}
		}
		else if (curDir == 3) {  // West
			if (curDir == dir) {
				result += abs(curDist - dist);
			}
			else if (dir == 1) {
				result += min((curDist + dist), (H - curDist + W + H + W - dist));
			}
			else if (dir == 2) {
				result += min((H - curDist + dist), (curDist + W + H + W - dist));
			}
			else if (dir == 4) {
				result += min((curDist + W + dist), (H - curDist + W + H - dist));
			}
		}
		else if (curDir == 4) {  // East
			if (curDir == dir) {
				result += abs(curDist - dist);
			}
			else if (dir == 1) {
				result += min((curDist + W - dist), H - curDist + W + H + dist);
			}
			else if (dir == 2) {
				result += min((H - curDist + W - dist), curDist + W + H + dist);
			}
			else if (dir == 3) {
				result += min((curDist + W + dist), (H - curDist + W + H - dist));
			}
		}
	}
	cout << result;
}