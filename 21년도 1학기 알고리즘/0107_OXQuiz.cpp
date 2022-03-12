#pragma warning (disable:4996)
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int OXQuiz(string str) {
	int len = str.length(); //문자열의 길이
	int startIndex = 0; //검색을 시작할 Index 위치
	int result = 0; // 결과 값
	while (true) {
		int fIndex = str.find("X", startIndex); // fIndex : "X" 를 찾은 인덱스

		if (fIndex == -1) {					//더이상 "X"를 찾을 수 없다면 마지막으로 "X"가 발견된
			for (int j = 1; j <= len - startIndex; j++) //인덱스에서 문자열의 끝까지
				result += j;							 //점수를 더하기 위한 코드

			return result;	//result를 리턴하고 종료
		}
		for (int j = 1; j <= fIndex - startIndex; j++) {
			result += j; //"X"를 찾는 만큼 점수를 더해주기 위한 코드
		}
		startIndex = fIndex + 1; //"X"를 찾았을 때 바로 다음 인덱스부터 재검색을 위함
	}
	return result;
}

int main() {
	freopen("input1.txt", "r", stdin);
	int T;
	cin >> T;	
	string num;
	vector<string> ox; //string형 배열 선언

	for (int i = 0; i < T; i++) {
		cin >> num;
		ox.push_back(num); 
		cout << OXQuiz(ox.at(i)) << endl; // 배열의 원소를 함수의 인수로 전달
	}
}