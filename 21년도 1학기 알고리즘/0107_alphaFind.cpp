/*알파벳 소문자로만 이루어진 단어 S가 주어진다.각각의 알파벳에 대해서, 
단어에 포함되어 있는 경우에는 처음 등장하는 위치를, 
포함되어 있지 않은 경우에는 - 1을 출력하는 프로그램을 작성하시오.*/

#pragma warning (disable: 4996)
#include <iostream>
#include <string>
using namespace std;

void alphaFind(string str, int result[]) {
	//알파벳 찾기를 위한 문자열 배열 선언
	string alphavet[26] = { "a", "b", "c", "d", "e", "f", "g", "h", "i",
	"j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v",
	"w", "x", "y", "z" };

	for (int i = 0; i < 26; i++) { //"a"-"z"까지 찾기위해 배열 인수의 개수인 26번 반복
		int fIndex = str.find(alphavet[i]); //"a"-"z"까지 찾는다면 fIndex에 인덱스를 저장

		result[i] = fIndex; //fIndex를 result배열에 바로 대입
	}
}
int main() {
	int result[26]; // 알파벳 개수인 26만큼의 정수형 배열 선언
	fill_n(result, 26, -2); // result 배열을 -2로 초기화

	string str;
	cout << "단어를 입력하세요.";
	cin >> str;

	alphaFind(str, result);

	for (int i = 0; i < 26; i++)
		cout << result[i] << ' ';
}

