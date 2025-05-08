#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    
    unordered_map<string, int> um;
    for(int i = 0; i < N; i++) {
        string keyword;
        cin >> keyword;
        um[keyword] = 1;
    }

    for(int i = 0; i < M; i++) {
        string word;
        cin >> word;

        stringstream ss(word);
        string w;
        vector<string> result;
        while (getline(ss, w, ',')) {
            result.push_back(w);
        }

        for(string s: result) {
            if(um.find(s) != um.end()) um.erase(s);
        }

        cout << um.size() << "\n";
    }

    return 0;
}