#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> v(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }

    vector<int> tmp(v);
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());

    map<int, int> m;
    for(int i = 0; i < tmp.size(); i++) {
        m[tmp[i]] = i;
    }

    for(int i = 0; i < N; i++) {
        cout << m[v[i]] << ' ';
    }
    cout << '\n';

    return 0;
}