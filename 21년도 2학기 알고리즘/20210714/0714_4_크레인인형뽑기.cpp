#include <string>
#include <vector>
#include <stack>
using namespace std;

 // 기본: board[i][j]에서 j는 고정. i만 탐색
int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s;
    s.push(-1); //초기에 스택에 상관없는 값 '-1'를 넣어줌
    for (int i = 0; i < moves.size(); i++) { //moves의 크기 만큼 인형 뽑기를 시도해야함.
        for (int j = 0; j < board.size(); j++) { // board.size() = 행 크기 만큼 탐색을 시도.
            int tmp = moves[i] - 1; // 0부터 시작하는 index 값 조정
            if (board[j][tmp] != 0) { //board 배열에 있는 값이 0이 아닌 인형이라면, num 변수에 s.top() 값을 넣고 뽑은 인형을 push
                int num = s.top();
                s.push(board[j][tmp]);
                board[j][tmp] = 0; // 인형을 뽑았으니, 해당 board를 0으로 초기화
                if (s.top() == num) { // 이전에 있던 인형. 즉 num과 방금 뽑은 인형이 같다면, answer += 2;
                    answer += 2;
                    s.pop(); s.pop(); //s.pop()을 2번해줘서 인형을 터친다.
                }
                break; //계속 continue로 하다가 틀렸는데 break로 하니 맞았습니다.
            }
        }
    }
    return answer;
}