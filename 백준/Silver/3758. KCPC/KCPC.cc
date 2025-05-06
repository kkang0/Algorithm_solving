#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int team[101][101];
int cnt[101];
int submit[101];
int score[101];

bool compare(int a, int b) {
    if(score[a] != score[b]) return score[a] > score[b];
    if(cnt[a] != cnt[b]) return cnt[a] < cnt[b];
    return submit[a] < submit[b];
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--) {
        int n, k, t, m;
        cin >> n >> k >> t >> m;

        memset(team, 0, sizeof(team));
        memset(cnt, 0, sizeof(cnt));
        memset(submit, 0, sizeof(submit));
        memset(score, 0, sizeof(score));

        for(int i = 1; i <= m; i++) {
            int id, num, score;
            cin >> id >> num >> score;
            
            team[id][num] = max(team[id][num], score);
            cnt[id]++;
            submit[id] = i;
        }

        for (int i = 1; i <= n; i++) {
            score[i] = 0;
            for (int j = 1; j <= k; j++) {
                score[i] += team[i][j];
            }
        }

        vector<int> rank;
        for(int i = 1; i <=n; i++) rank.push_back(i);

        sort(rank.begin(), rank.end(), compare);

        for(int i = 0; i < n; i++) {
            if(rank[i] == t) {
                cout << i + 1 << "\n";
            }
        }
    }

    return 0;
}