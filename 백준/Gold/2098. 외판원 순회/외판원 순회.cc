#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 1e9;
int N, B;
int city[16][16];
int dp[16][1 << 16];
int result = 0;

int tsp(int cur, int bitset) {
    if(B == bitset) {
        if(city[cur][0] == 0) return INF;
        return city[cur][0];
    }

    if(dp[cur][bitset] >= 0) return dp[cur][bitset];
    dp[cur][bitset] = INF;

    for(int i = 0; i < N; i++) {
        if(!city[cur][i] || bitset & (1 << i)) continue;
        int cost = tsp(i, bitset | (1 << i));
        dp[cur][bitset] = min(dp[cur][bitset], city[cur][i] + cost);
    }

    return dp[cur][bitset];
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> city[i][j];
        }
    }
    
    B = (1 << N) - 1;
    cout << tsp(0, 1) << '\n';

    return 0;
}