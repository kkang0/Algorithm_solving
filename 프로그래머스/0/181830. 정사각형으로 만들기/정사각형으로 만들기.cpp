#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr) {
    int col = arr[0].size();
    int row = arr.size();
    if(row > col) {
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < row - col; j++) {
                arr[i].push_back(0);
            }
        }
    } else if(row < col) {
        for(int i = 0; i < col - row; i++) {
            vector<int> v(col, 0);
            arr.push_back(v);
        }
    }
    
    return arr;
}