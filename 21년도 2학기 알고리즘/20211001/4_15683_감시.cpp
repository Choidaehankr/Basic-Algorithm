#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int office[8][8];
int tmp_arr[8][8];

void rotation(int x, int y) {
	// 1일 경우) 4번 회전.
	// 1-1) for-loop 4번으로 if(!arr[x][y])라면 arr[x][y+1], arr[x+1][y], arr[x-1][y], arr[x][y-1] = #
	// 2일 경우) 2번 회전
	// 3일 경우) 4번 회전
	// 4일 경우) 4번 회전
	// 5일 경우) 1번 회전

	// CCTV 종류별 회전 함수를 5개 만든다?
	// 회전 시킨 후 사각 지대의 개수가 최소가 되는 경우의 배열(tmp_arr)을 저장시킨다.
	// 모든 CCTV 회전 결과를 tmp_arr에 갱신시켜 준다...?
}

int main() {
	int N, M;
	cin >> N >> M;
	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int num; cin >> num;
			office[i][j] = num;
			if (num != 0 && num != 6) {
				v.push_back({ i, j }); //CCTV의 위치를 v에 PUSH
			}
		}
	}
	int num = 0;
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first;
		int y = v[i].second;
		rotation(x, y);
	}
}