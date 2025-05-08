#include <iostream>
#include <unordered_set>
#include <sstream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    unordered_set<string> keywords;
    for (int i = 0; i < N; ++i) {
        string word;
        cin >> word;
        keywords.insert(word);
    }

    for (int i = 0; i < M; ++i) {
        string line;
        cin >> line;

        stringstream ss(line);
        string token;
        while (getline(ss, token, ',')) {
            keywords.erase(token);
        }

        cout << keywords.size() << '\n';
    }

    return 0;
}