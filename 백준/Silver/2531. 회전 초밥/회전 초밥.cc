#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, d, k, c;
vector<int> v;
int cnt[3001];
int result = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> d >> k >> c;
    v.resize(N);

    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }

    int kind = 0;
    for(int i = 0; i < k; i++) {
        if(cnt[v[i]] == 0) kind++;
        cnt[v[i]]++;
    }

    result = kind + (cnt[c] == 0 ? 1 : 0);

    for(int i = 1; i < N; i++) {
        int remove = v[i - 1];
        cnt[remove]--;
        if(cnt[remove] == 0) kind--;

        int add = v[(i + k - 1) % N];
        if(cnt[add] == 0) kind++;
        cnt[add]++;

        result = max(result, kind + (cnt[c] == 0 ? 1 : 0));
    }

    cout << result << "\n";

    return 0;
}