#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> activate;
vector<int> deactivate;
int dp[100001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    activate.resize(N);
    deactivate.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> activate[i];
    }

    for(int i = 0; i < N; i++) {
        cin >> deactivate[i];
    }

    int maxCost = 10000;
    for(int i = 0; i < N; i++) {
        for(int j = maxCost; j >= 0; j--) {
            if(j >= deactivate[i]) dp[j] = max(dp[j], dp[j - deactivate[i]] + activate[i]);
        }
    }

    int cost = 0;
    while(dp[cost] < M) cost += 1;

    cout << cost << '\n';

    return 0;
}