#include <iostream>
#include <vector>
using namespace std;
int main() {
	vector<vector<int>> v; //2차원 벡터 v 선언
	int i = 0;
	while (1) {
		int L, P, V;
		vector<int> v1; //v에 대입하기 위한 1차원 벡터 v1선언
		cin >> L >> P >> V;
		if (L == 0 && P == 0 && V == 0) // 0 0 0이 입력됐을때 종료
			break;
		v1.push_back(L);
		v1.push_back(P);
		v1.push_back(V);
		v.push_back(v1); //v1을 v에 push_back!
		i++; // 몇개의 case인지 확인하기 위한 변수 i 증가.
	}
	 //최대 사용 가능 일 수는 ((사용 가능 일 * (휴가 일 / 연속한 일)) + (휴가일 % 연속한 일))
	for (int n = 0; n < i; n++) {
		int L = v[n][0], P = v[n][1], V = v[n][2]; // L = 사용 가능 일, P = 연속 일, V = 휴가
		int num;
		if (V % P > L) // 휴가를 연속하는 일수로 나눈 나머지가 사용가능일 보다 클 경우
			num = L; // num은 사용 가능 일수.
		else num = V % P; // num = 작을 경우 휴가를 연속하는 일로 나눈 수
		int sum = (V / P) * L + num;
		cout << "Case " << n + 1 << ": " << sum << endl;
	}
}