#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    int len = num_list.size() / n;
    vector<vector<int>> v(len, vector<int>(n));
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < n; j++) {
            v[i][j] = num_list[i * n + j];
        }
    }
    
    return v;
}