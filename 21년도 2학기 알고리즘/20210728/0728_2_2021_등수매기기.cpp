#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N; cin >> N;
	vector <int> v;
	long long int result = 0; //�ڷ��� ����
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		v.push_back(num);
	}
	// ���� ������ �������� ����. ���� ���(?)���� ���� �� ������ ���� ���� result�� ���Ѵ�.
	sort(v.begin(), v.end()); 
	for (int i = 0; i < v.size(); i++) {
		result += abs((i+1) - v[i]); 
	}
	cout << result;
}