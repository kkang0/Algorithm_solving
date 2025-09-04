#include <iostream>
#include <set>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    set<string> ms;
    for(int i = 0; i < s.size(); i++) {
        for(int j = i; j < s.size(); j++) {
            ms.insert(s.substr(i, j - i + 1));
        }
    }

    cout << ms.size() << '\n';

    return 0;
}