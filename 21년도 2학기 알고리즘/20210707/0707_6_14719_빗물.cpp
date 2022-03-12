#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//빗물을 확인할 위치 i에서 왼쪽 & 오른쪽에서 각각 가장 큰 블록 값을 찾고.
//위에서 찾은 두개 중 더 작은 값에서 i 값 (현재 블록의 크기)을 빼준다.
int main() {
	int H, W;
	cin >> H >> W;

	vector <int> v;
	for (int i = 0; i < W; i++) {
		int num; cin >> num;
		v.push_back(num);
	}
	int sum = 0, left, right;
	for (int i = 1; i < W - 1; i++) {
		left = right = v[i]; // 현재 위치 i를 기준으로 잡음
		for (int j = 0; j < i; j++) { //0부터 i번째 위치까지 왼쪽에 존재하는 블록의 최대 크기를 탐색
			left = max(left, v[j]);
		}
		for (int k = i + 1; k < W; k++) { //i+1번째에서 끝(W)까지 오른쪽에 존재하는	"" ""
			right = max(right, v[k]);
		}
		sum += min(right, left) - v[i]; //오른쪽, 왼쪽 중 최소값에서 현재 값 v[i]를 뺀 후 sum에 누적
	}
	cout << sum;
}