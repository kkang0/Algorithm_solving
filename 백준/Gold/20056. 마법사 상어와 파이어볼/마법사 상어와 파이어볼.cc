#include <iostream>
#include <vector>
using namespace std;

int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    vector<int> r(M), c(M), m(M), s(M), d(M);
    for(int i = 0; i < M; i++) {
        cin >> r[i] >> c[i] >> m[i] >> s[i] >> d[i];
    }

    while(K--) {
        vector<vector<vector<int>>> grid(N + 1, vector<vector<int>>(N + 1));
        for(int i = 0; i < r.size(); i++) {
            int nr = (r[i] + dr[d[i]] * s[i] - 1) % N + 1;
            int nc = (c[i] + dc[d[i]] * s[i] - 1) % N + 1;
            if(nr <= 0) nr += N;
            if(nc <= 0) nc += N;
            r[i] = nr;
            c[i] = nc;
            grid[nr][nc].push_back(i);
        }

        vector<int> nr, nc, nm, ns, nd;
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(grid[i][j].empty()) continue;

                if(grid[i][j].size() == 1) {
                    int idx = grid[i][j][0];
                    nr.push_back(r[idx]);
                    nc.push_back(c[idx]);
                    nm.push_back(m[idx]);
                    ns.push_back(s[idx]);
                    nd.push_back(d[idx]);
                } else {
                    int sum_m = 0, sum_s = 0;
                    bool all_even = true, all_odd = true;
                    for(int idx : grid[i][j]) {
                        sum_m += m[idx];
                        sum_s += s[idx];
                        if(d[idx] % 2 == 0) all_odd = false;
                        else all_even = false;
                    }
                    int new_m = sum_m / 5;
                    if(new_m == 0) continue;
                    int new_s = sum_s / grid[i][j].size();
                    vector<int> new_dirs = (all_even || all_odd) ? vector<int>{0,2,4,6} : vector<int>{1,3,5,7};

                    for(int ndir : new_dirs) {
                        nr.push_back(i);
                        nc.push_back(j);
                        nm.push_back(new_m);
                        ns.push_back(new_s);
                        nd.push_back(ndir);
                    }
                }
            }
        }

        r = nr;
        c = nc;
        m = nm;
        s = ns;
        d = nd;
    }

    int result = 0;
    for(int i = 0; i < m.size(); i++) result += m[i];
    cout << result << '\n';

    return 0;
}