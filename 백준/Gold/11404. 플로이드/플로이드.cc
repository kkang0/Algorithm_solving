#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int n, m;
vector<vector<int>> arr;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    cin >> m;

    arr.resize(n + 1, vector<int>(n + 1, INF));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) arr[i][j] = 0;
        }
    }

    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a][b] = min(arr[a][b], c);
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(arr[i][j] == INF) cout << 0 << ' ';
            else cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}