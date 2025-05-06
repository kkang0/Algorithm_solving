#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<pair<string, int>> v(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
    }

    for(int i = 0; i < M; i++) {
        int x;
        cin >> x;

        int left = 0;
        int right = N - 1;
        int mid = 0;
        while(left <= right) {
            mid = (left + right) / 2;

            if(x <= v[mid].second) {
                right = mid - 1;
            } else left = mid + 1;
        }

        if(x > v[mid].second) cout << v[mid + 1].first << "\n";
        else cout << v[mid].first << "\n";
    }

    return 0;
}