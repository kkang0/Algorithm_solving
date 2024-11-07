#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 1e9
using namespace std;

int solution(int x, int y, int n) {
    vector<int> dp(y + 1, MAX);
    dp[x] = 0;
    
    for (int i = x; i <= y; i++) {
        if (dp[i] == MAX) continue;
        
        if (i + n <= y) dp[i + n] = min(dp[i + n], dp[i] + 1);
        
        if (i * 2 <= y) dp[i * 2] = min(dp[i * 2], dp[i] + 1);
        
        if (i * 3 <= y) dp[i * 3] = min(dp[i * 3], dp[i] + 1);
    }
    
    return dp[y] == MAX ? -1 : dp[y];
}