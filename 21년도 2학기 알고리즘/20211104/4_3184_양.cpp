#include <iostream>
using namespace std;

// 수평 수직 이동 = 4방향 이동 
// 울타리를 지나지 않고 이동한다면, 같은 영역
// 탈출할 수 있는 칸은 어떤 영역에도 속하지 않는다
// 영역안의 양의 수가 늑대보다 많으면 이기고, 쫓아냄.
// 그렇지 않으면 늑대한테 양이 다 먹힘 ㄷㄷ;


#define MAX 250
char yard[MAX][MAX];
bool visited[MAX][MAX];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int R, C;
int sheeps, wolves;
int resultSheeps, resultWolves;

bool yardRangeCheck(int x, int y) { //탐색 조건은 배열 내에 있고 울타리가 아닐 경우
	if (x >= 0 && x < R && y >= 0 && y < C && yard[x][y] != '#' && !visited[x][y])
		return true;
	else
		return false;
}

void DFS(int x, int y) {
	visited[x][y] = true;
	if (yard[x][y] == 'o') //늑대와 양을 만나면 각 개체 수를 증가
		sheeps += 1;
	else if (yard[x][y] == 'v')
		wolves += 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (yardRangeCheck(nx, ny)) { //조건에 맞춰 DFS탐색
			DFS(nx, ny);
		}
	}
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> yard[i][j];
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (!visited[i][j] && yard[i][j] != '#') { //울타리가 아니고 방문을 안했을 경우 DFS탐색
				DFS(i, j);
				if (sheeps > wolves) { //양이 더 많다면 늑대는 다 쫓겨남
					wolves = 0;
				}
				else {				// 늑대 >= 양이면, 다 잡아먹힘 ㅠ
					sheeps = 0;
				}
				resultSheeps += sheeps, resultWolves += wolves;		//다른 영역을 탐색하기 위해 남은 늑대와 양의 수를 resultXX에 누적시키고 0으로 초기화
				wolves = 0, sheeps = 0;
			}
		}
	}
	cout << resultSheeps << ' ' << resultWolves << endl;
}