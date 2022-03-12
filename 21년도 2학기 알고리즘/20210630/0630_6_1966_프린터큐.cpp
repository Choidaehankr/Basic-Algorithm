#include<iostream>
#include <queue>
using namespace std;

int main() {
	int T; cin >> T;
	for (int i = 0; i < T; i++) {
		queue<pair<int, int>> q; //M번째 문서를 파악하기 위해 pair 사용
		priority_queue<int> pq; //우선순위를 비교할 우선순위 큐 선언
		int N, M, result = 0;
		cin >> N >> M;
		for (int j = 0; j < N; j++) {
			int num; cin >> num;
			pq.push(num);
			q.push({ j, num }); //우선순위 큐인 pq에는 문서의 우선순위가 내림차순으로 정렬
								//일반 큐 q에는 문서의 번호와 우선순위가 들어감.
		}
		while (!q.empty()) {
			int index = q.front().first; //index에는 문서의 번호
			int prior = q.front().second; //prior에는 문서의 우선순위
			
			if (pq.top() == prior) { //현재 문서의 우선순위가 가장 높다면 출력
				result++;
				pq.pop(); 
					if (index == M) { //우선순위가 가장 높으면서 M번째의 문서라면
					cout << result << endl;
					break;
				}
			}
			else {
				q.push({ index, prior }); //아니라면 그대로 다시 push.....
			}
			q.pop();
		}
	}
}