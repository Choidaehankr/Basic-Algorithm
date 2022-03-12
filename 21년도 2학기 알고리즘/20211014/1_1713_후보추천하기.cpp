#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, minNum = 1000;
bool check = false;
vector<pair<int, int>> v;
int main() {
	cin >> N >> M;
	int cnt = 1;
	for (int i = 0; i < M; i++) {
		int num; cin >> num;
		minNum = 1000;
		check = false;
		for (int j = 0; j < v.size(); j++) {	//사진틀에 있는지 확인
			if (num == v[j].first) { //사진 틀에 있다면, check을 true로 변환
				check = true;		 //추천받은 횟수를 증가시킴
				v[j].second++;
				break;
			}
		}
		if (!check) { // 새로 액자에 들어갈 학생인 경우
			if (v.size() < N) { //액자에 빈자리가 있는 경우
				v.push_back({ num, 1 }); //냅다 집어넣고,
			}
			else { //액자가 가득 찬 경우
				for (int k = 0; k < v.size(); k++) { // 사진틀에 있는 학생중 추천수가 가장 적은 학생을 찾는다.
					minNum = min(minNum, v[k].second);
				}
				for (int l = 0; l < v.size(); l++) { //벡터의 크기 만큼 돌면서 추천수가 최솟값인 학생을 찾으면 지워준다.
					if (v[l].second == minNum) {	//push_back으로 넣었으므로 가장 처음 발견하면 지워주고 break;
						v.erase(v.begin() + l);
						break;
					}
				}
				v.push_back({ num, 1 }); //새로운 후보를 추천수 1로 하고 넣어준다.
			}
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << ' ';
	}
}