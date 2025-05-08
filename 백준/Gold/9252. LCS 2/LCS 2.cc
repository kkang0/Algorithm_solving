#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> dp;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string l, s;
    cin >> l;
    cin >> s;

    // l이 더 길어
    if(l.size() < s.size()) {
        swap(l, s);
    }

    int L = l.size();
    int S = s.size();
    
    dp.resize(L + 1, vector<int>(S + 1, 0));

    for(int i = 0; i < S; i++) {
        dp[0][i] = 0;
    }

    for(int i = 1; i <= L; i++) {
        for(int j = 1; j <= S; j++) {
            if(i == 0 || j == 0) dp[i][j] = 0;
            else if (l[i - 1] == s[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }

        }
    }

    string result;
    int i = L;
    int j = S;
    while (i > 0 && j > 0) {
        if (l[i - 1] != s[j - 1]) {
            if (dp[i - 1][j] > dp[i][j - 1]) i--;
            else j--;
        } else {
            result += l[i - 1];
            i--;
            j--;
        }
    }


    reverse(result.begin(), result.end());

    cout << dp[L][S] << "\n" << result << "\n";

    return 0;
}