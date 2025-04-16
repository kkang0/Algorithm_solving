#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int N, D;
vector<pair<int, int>> route[10001];
vector<int> dis(10001, 10001);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> D;

    for(int i = 0; i < N; i++) {
        int s, e, d;
        cin >> s >> e >> d;
        if(e > D || e - s < d) continue;
        route[s].push_back({e, d});
    }

    dis[0] = 0;
    for (int i = 0; i <= D; i++) {
        if (i + 1 <= D) dis[i + 1] = min(dis[i + 1], dis[i] + 1);

        for (int j = 0; j < route[i].size(); j++) {
            int e = route[i][j].first;
            int d = route[i][j].second;

            if (e <= D) {
                dis[e] = min(dis[e], dis[i] + d);
            }
        }
    }

    cout << dis[D] << "\n";

    return 0;
}