
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int result = 0;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	for (int i = 0; i < n - 2; i++) { //3장의 카드를 접근하기위해 3중 반복문에 변수 i,j,k
		for (int j = i + 1; j < n - 1; j++) { 
			for (int k = j + 1; k < n; k++) { // k는 j+1부터 n 까지 접근 
				int sum = v[i] + v[j] + v[k]; // sum에 3장의 카드의 합을 저장합니다.
				if (sum == m) { //sum과 m이 같게되면 오면 바로 종료
					result = sum;
					break;
				}	
				else if (sum < m && sum > result) // sum이 m보다 작고, 이전에 계산한 result 보다 크다면
					result = sum; // m에 더 근사한 값이 있다는 뜻으로 result에 sum을 넣고 loop를 마저 돕니다.
			}
		}
	}
	cout << result; //result값 출력.
}

//처음엔 재귀함수로 풀려고 했으나 cnt값 관리와 이전에 계산한 인덱스를 다음 재귀 호출에서 처리하는데 어려움을 겪어 포기.