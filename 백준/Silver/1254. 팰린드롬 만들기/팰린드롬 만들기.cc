#include <iostream>
#include <string>
using namespace std;

string s;

bool isPalindrom(string str) {
    int cnt = str.size() / 2;
    for(int i = 0; i < cnt; i++) {
        if(str[i] != str[str.size() - 1 - i]) return false;
    }
    return true;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;

    int n = s.size();
    int result = 2 * n;

    for(int i = 0; i < n; i++) {
        string post = s.substr(i, n - i);

        if(isPalindrom(post)) {
            result = n + i;
            break;
        }
    }

    cout << result << '\n';

    return 0;
}