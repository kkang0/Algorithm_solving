#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<string> words(N);
    for(int i = 0; i < N; i++) {
        cin >> words[i];
    }

    string base = words[0];
    int result = 0;

    for(int i = 1; i < N; i++) {
        string target = words[i];

        int cnt1[26] = {0};
        int cnt2[26] = {0};

        for(char c : base) cnt1[c - 'A']++;
        for(char c : target) cnt2[c - 'A']++;

        int diff = 0;
        for(int j = 0; j < 26; j++) {
            diff += abs(cnt1[j] - cnt2[j]);
        }

        if (diff == 0) result++;
        else if (diff == 1) result++;
        else if (diff == 2 && base.size() == target.size()) result++;
    }

    cout << result << "\n";
    return 0;
}