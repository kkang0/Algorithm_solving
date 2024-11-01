#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    vector<vector<bool>> v(n + 1, vector<bool>(n + 1, false));
    
    for(auto a: results) {
        v[a[0]][a[1]] = true;
    }
    
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if (v[i][k] && v[k][j]) v[i][j] = true;
            }
        }
    }
    
    int answer = 0;
    for(int i = 1; i <= n; i++) {
        int cnt = 0;
        for(int j = 1; j <= n; j++) {
            if(v[i][j] == true || v[j][i] == true) cnt++;
        }
        
        if(cnt == n - 1) answer++;
    }
    
    return answer;
}