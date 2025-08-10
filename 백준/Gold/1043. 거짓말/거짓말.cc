#include <iostream>
#include <vector>
using namespace std;

int N, M, K;
vector<int> truth;
vector<int> party[53];
int parent[53];

int find(int x) {
    if(parent[x] == x) return x;
    return x = find(parent[x]);
}

void union_parent(int x, int y) {
    x = find(x);
    y = find(y);
    parent[x] = y;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;

    for(int i = 0; i < K; i++) {
        int t;
        cin >> t;
        truth.push_back(t);
    }

    for(int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    for(int i = 0; i < M; i++) {
        int p;
        cin >> p;

        int num, prev;
        for(int j = 0; j < p; j++) {
            if(j >= 1) {
                prev = num;
                cin >> num;
                union_parent(prev, num);
            } else {
                cin >> num;
            }
            party[i].push_back(num);
        }
    }

    int result = M;
    for(auto& p: party) {
        bool flag = false;
        for(auto& person: p) {
            if(flag) break;
            for(auto& t: truth) {
                if(find(person) == find(t)) {
                    flag = true;
                    break;
                }
            }
        }
        if(flag) result--;
    }

    cout << result << '\n';

    return 0;
}