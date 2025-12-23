#include <iostream>
#include <unordered_map>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    unordered_map<string, string> site;
    for(int i = 0; i < N; i++) {
        string s, p;
        cin >> s >> p;
        site[s] = p;
    }

    for(int i = 0; i < M; i++) {
        string s;
        cin >> s;
        cout << site[s] << '\n';
    }

    return 0;
}