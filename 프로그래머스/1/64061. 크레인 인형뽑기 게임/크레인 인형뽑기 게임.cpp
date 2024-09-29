#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    stack<int> stk;
    int result = 0;
    
    for(int i = 0; i < moves.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
            if(board[j][moves[i] - 1] != 0) {
                if(!stk.empty() && stk.top() == board[j][moves[i] - 1]) {
                    stk.pop();
                    board[j][moves[i] - 1] = 0;
                    result += 2;
                } else {
                    stk.push(board[j][moves[i] - 1]);
                    board[j][moves[i] - 1] = 0;
                }
                break;
            }
        }
    }
    
    return result;
}