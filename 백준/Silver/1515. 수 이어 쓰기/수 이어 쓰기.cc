#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = 1;
    int idx = 0;
    while(true) {
        if(idx == s.size()) break;

        string num = to_string(n);
        for(int i = 0; i < num.size(); i++) {
            if(s[idx] == num[i]) idx++;
        }

        n++;
    }

    cout << n - 1 << "\n";

    return 0;
}