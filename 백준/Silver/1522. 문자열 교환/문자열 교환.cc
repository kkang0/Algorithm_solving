#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;

    int a_cnt = count(s.begin(), s.end(), 'a');
    int n = s.size();
    string doubled_s = s + s;

    int min_swaps = n;
    int b_cnt = 0;

    for (int i = 0; i < a_cnt; i++) {
        if (doubled_s[i] == 'b') b_cnt++;
    }
    min_swaps = b_cnt;

    for (int i = 1; i < n; i++) {
        if (doubled_s[i - 1] == 'b') b_cnt--;
        if (doubled_s[i + a_cnt - 1] == 'b') b_cnt++;

        min_swaps = min(min_swaps, b_cnt);
    }

    cout << min_swaps << endl;
    return 0;
}