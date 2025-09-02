#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;

    char prev = S[0];
    int cnt0 = 0;
    int cnt1 = 0;

    if(prev == '0') cnt0++;
    else cnt1++;

    for(int i = 1; i < S.size(); i++) {
        if(S[i] != prev) {
            if(S[i] == '0') cnt0++;
            else cnt1++;
            prev = S[i];
        }
    }

    cout << min(cnt0, cnt1) << '\n';

    return 0;
}