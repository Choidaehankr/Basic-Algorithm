 #include <iostream>
using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B; //A�� B�� ���� �ð�
	cin >> C; // C�� �ʿ��� �ð�
	for (int i = 1; i <= C; i++) {
		B++;
		if (B >= 60) {
			B = 0; //59�п��� 60������ �Ѿ�� 0������ �ʱ�ȭ
			A++;
		}
		if (A >= 24) {
			A = 0; //23�ÿ��� 24�÷� �Ѿ�� 0�÷� �ʱ�ȭ.
		}
	}
	cout << A << ' ' << B;
}