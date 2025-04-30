#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;

    int c0 = 0;
    int c1 = 0;
    for(char c: S) {
        if(c == '0') c0++;
        else if(c == '1') c1++;
    }

    string str(c0 / 2, '0');
    str += string(c1 / 2, '1');

    cout << str << "\n";

    return 0;
}