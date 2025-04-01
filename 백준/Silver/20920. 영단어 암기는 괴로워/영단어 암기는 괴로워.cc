#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map<string, int> m;

bool compare(const string &a, const string &b) {
    if (m[a] == m[b]) {
        if (a.size() == b.size()) return a < b;
        return a.size() > b.size();
    }
    return m[a] > m[b];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<string> word;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        
        if (s.size() < M) continue;

        if (m.find(s) == m.end()) {
            word.push_back(s);
        }
        m[s]++;
    }

    sort(word.begin(), word.end(), compare);

    for (const string &w : word) {
        cout << w << "\n";
    }

    return 0;
}