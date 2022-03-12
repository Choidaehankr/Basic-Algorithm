 #include <iostream>
using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B; //A와 B는 현재 시각
	cin >> C; // C는 필요한 시각
	for (int i = 1; i <= C; i++) {
		B++;
		if (B >= 60) {
			B = 0; //59분에서 60분으로 넘어가면 0분으로 초기화
			A++;
		}
		if (A >= 24) {
			A = 0; //23시에서 24시로 넘어가면 0시로 초기화.
		}
	}
	cout << A << ' ' << B;
}