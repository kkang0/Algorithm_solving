#include <string>
#include <vector>
#include <cstring>
using namespace std;

bool visited[201];

void dfs(int i, int n, vector<vector<int>> computers) {
    visited[i] = true;
    
    for(int j = 0; j < n; j++) {
        if(!visited[j] && computers[i][j] == 1) {
            dfs(j, n, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int result = 0;
    memset(visited, false, sizeof(visited));
    
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i, n, computers);
            result++;
        }
    }
    
    return result;
}