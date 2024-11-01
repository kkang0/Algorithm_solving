#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int arr[101][101] = {0};
    
    for(int i = 0; i < puddles.size(); i++) {
        arr[puddles[i][1]][puddles[i][0]] = -1;
    }
    
    arr[1][1] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int x = 0;
            int y = 0;
            if(arr[i][j] == -1) continue;
            if(arr[i - 1][j] != -1) x = arr[i - 1][j];
            if(arr[i][j - 1] != -1) y = arr[i][j - 1];
            
            arr[i][j] += (x + y) % 1000000007;
        }
    }
    
    return arr[n][m];
}