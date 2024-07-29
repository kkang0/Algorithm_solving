#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board) {
    int n = board.size();
    vector<vector<int>> directions{{1, 1}, {1, 0}, {1, -1}, {0, 1}, {0, -1}, {-1, 1}, {-1, 0}, {-1, -1}};
    
    int result = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (board[i][j] == 1) continue;
            
            bool is_valid = true;
            for(const auto& dir : directions) {
                int new_i = i + dir[0];
                int new_j = j + dir[1];
                
                if(new_i < 0 || new_i >= n || new_j < 0 || new_j >= n) {
                    continue;
                }
                
                if(board[new_i][new_j] == 1) {
                    is_valid = false;
                    break;
                }
            }
            
            if (is_valid) {
                result++;
            }
        }
    }
    return result;
}
