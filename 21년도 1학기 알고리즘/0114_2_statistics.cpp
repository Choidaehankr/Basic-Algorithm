#pragma warning (disable:4996)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n = 0;
	cin >> n;
	int mst = 0; //최빈값
	vector<vector<int>> v(n, vector<int>(2)); //최빈값 표시를 위해 2차원 벡터 선언

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (n <= 1) //n이 1이하라면 최빈값은 num
			mst = num;
		for (int j = 0; j <= i; j++) { //num이 존재하는지 체크
			if (v[j][0] == num) { //v[j][0]에 num이 이미 존재한다면
				v[j][1]++; //빈도수에 해당하는 v[j][1]을 1더함.
				break;
			}
		}
		v[i][0] = num; //v[i][0]에 num을 넣고
		v[i][1] = 1; //v[i][1]에는 빈도수를 넣는다.
	}
	sort(v.begin(), v.end()); //오름차순 정렬

	//최빈값

	if (n > 1) { 
		vector<int> vect; //1차원 벡터 선언
		mst = v[0][1]; // 일단 v[0][1]을 빈도수로 설정
		for (int i = 0; i < n; i++) {
			if (mst <= v[i][1]) //v[i][1]이 mst보다 크다면 mst는 v[i][1]
				mst = v[i][1];
		}

		for (int i = 0; i < n; i++) {
			if (v[i][1] == mst)
				vect.push_back(v[i][0]); //최빈값이 여러개일 경우 vect에 push_back
		}
		sort(vect.begin(), vect.end()); //최빈값들을 정렬
		mst = vect[1]; // 2번째로 작은 값 선택
	}
	else mst = v[0][0]; //n이 1이면 v[0][0]이 최빈값

	int min = v[0][0]; // 최소값
	int max = v[n - 1][0]; // 최대값
	int sum = 0; //평균 값
	for (int i = 0; i < n; i++) {
		sum += v[i][0] * v[i][1]; //값과 빈도수를 곱해서 더해줌
	}	
	cout << sum / n << endl; //산술 평균 값
	cout << v[n / 2][0] << endl; // 중앙 값
	cout << mst << endl; //최빈값
	cout << max - min << endl; //범위
}

// 시간 초과ㅜㅠ