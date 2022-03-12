#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//내림차순으로 정렬한 뒤 3개씩 묶어서 3번째 물건의 값만 빼주면 되겠다고 생각함.

int main() {
	int N;
	cin >> N;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end(), greater<>());  //내림차순 정렬
	int sum = 0;
	for (int i = 0; i < N; i++) {
		if (N >= 3) { //물건의 개수가 3개 이상이여야 할인 적용
			if ((i + 1) % 3 == 0) // index는 0부터 시작하므로 i+1이 3의 배수일 경우 (3번째 상품일 경우)
				continue; // sum에 물건 값을 더하지 않고 할인 받음. (continue 처리)
			else
				sum += v[i]; // sum에 가격을 누적시킴
		}
		else { //물건의 개수가 3개 이하일 경우 할인 없이 계산
			sum += v[i];
		}
	}
	cout << sum;
}