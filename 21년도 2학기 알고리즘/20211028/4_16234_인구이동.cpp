#include <iostream>
#include <queue>
using namespace std;
int N, R, L;
int arr[50][50];
int check[50][50];
int result[50][50];
bool visited[50][50];
bool startCheck[50][50];

int flag = 1;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int moveCount = 0; //최종 구할 결과 값
queue <pair<int, int>> q;

// 접근
// arr배열에 인구수를 받고 arr와 똑같은 배열 result를 만든다.
// 

//3.. movePopulation (40)

bool checkInterval(int x, int y, int nx, int ny) {
	if (arr[x][y] >= arr[nx][ny]) {
		if (arr[x][y] - arr[nx][ny] >= R && arr[x][y] - arr[nx][ny] <= L) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (arr[nx][ny] - arr[x][y] >= R && arr[nx][ny] - arr[x][y] <= L) {
			return true;
		}
		else {
			return false;
		}
	}
}

void movePopulation(int flag) {
	int sum = 0;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (check[i][j] == flag) { //flag 값이 들어있는 check 배열을 확인했을 때 '연합'이라면 인구이동
				sum += arr[i][j];
				cnt++;
			}
		}
	}
	sum = sum / cnt;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (check[i][j] == flag) {
				result[i][j] = sum; //arr와 동일한 배열 result에 인구 이동 결과를 담음
			}
		}
	}
	moveCount++; //여기에 쓰면 안될듯..
}

ㅠㅠ..........
ㅎㅎ..........

// flag 라는 변수로 '연합' 국가들을 정수로 묶고자함.

// 2.. checkInterval (20)

void BFS(int x, int y) {
	q.push({ x, y });
	check[x][y] = flag;
	visited[x][y] = true;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				continue;
			if (!visited[nx][ny]) {
				if (checkInterval(x, y, nx, ny)) { //checkInterval 함수로 두 국가 간 차를 계산
					check[nx][ny] = flag;	// 접근 가능한 국가를 check 배열에 flag 값으로 둠.
					visited[nx][ny] = true;
					startCheck[nx][ny] = true; // 해당 인덱스에서 시작이 가능하므로 startCheck를 true
					q.push({ nx, ny });
				}
			}
		}
	}
	movePopulation(flag); // 인구 이동 시작
	flag++; // 탐색을 시작한 나라에서 접근 불가한 나라이므로 flag값을 증가시켜 구분함
}

// (1) .. BFS (63)

int main() {
	cin >> N >> R >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num; cin >> num;
			arr[i][j] = num;
			result[i][j] = num;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) { // 국경선을 열 수 없는 나라에 접근했을 때 프로그램이 끝나는걸 방지하기 위해 	  
			if (!startCheck[i][j]) {  // startCheck 배열을 확인해서 BFS 돌릴려고 했는데 이것도 이상한듯..
				BFS(i, j);
			}
		}
	}

	// 확인용 코드
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << check[i][j] << ' ';
		}
		cout << endl;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << result[i][j] << ' ';
		}
		cout << endl;
	}

	cout << "MoveCount is " << moveCount << endl;
}