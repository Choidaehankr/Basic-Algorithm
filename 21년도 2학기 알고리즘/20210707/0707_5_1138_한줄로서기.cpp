#include <iostream>
#include <vector>
using namespace std;
int arr[11] = { };
vector<int> v;

int main() {
	int N; cin >> N;
	for (int i = 1; i <= N; i++) {
		int num; cin >> num;
		arr[i] = num;
	}

	//처음엔 1번 원소부터 배치해서 구현하여 시간을 많이 씀. 이후 뒤에서부터 접근해봄.
	//arr[N]은 무조건 값이 0. 즉, N보다 큰 사람이 없으므로 N부터 vector에 insert해줌.
	//arr[N-1]은 0 또는 1의 값. 0일경우 vector의 index [0]에 insert, 1일 경우, [1]에 insert하면 되는 원리.
	//마찬가지로 arr[i]에 있는 값 만큼 iterator (it) 를 증가 시킨후 insert함수를 사용해서 해결

	for (int i = N; i > 0; i--) {
		auto it = v.begin();
		for (int j = 0; j < arr[i]; j++) {
			it++; //arr[i]에 있는 값, 즉 자신의 왼쪽에 있는 사람 수 만큼 iterator를 증가시키는 과정
		}
		v.insert(it, i);
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}
}