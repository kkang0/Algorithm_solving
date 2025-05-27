#include <iostream>
#include <vector>
using namespace std;

const int MAX = 123457;
vector<int> tree[MAX];
char type[MAX];
long long cnt[MAX];

long long dfs(int node) {
    long long total = 0;

    for(int child: tree[node]) {
        total += dfs(child);
    }

    if(type[node] == 'S') {
        total += cnt[node];
    } else {
        total -= cnt[node];
        if(total < 0) total = 0;
    }

    return total;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for(int i = 2; i <= N; i++) {
        char t;
        int a, p;
        cin >> t >> a >> p;

        tree[p].push_back(i);
        type[i] = t;
        cnt[i] = a;
    }

    cout  << dfs(1) << '\n';

    return 0;
}