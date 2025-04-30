#include <iostream>
#include <string>
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

    c0 /= 2;
    c1 /= 2;

    while(c0 > 0) {
        int lastIdx0 = S.rfind('0');
        if(lastIdx0 != string::npos) {
            S.erase(lastIdx0, 1);
            c0--;
        }
    }

    while(c1 > 0) {
        int firstIdx1 = S.find('1');
        if(firstIdx1 != string::npos) {
            S.erase(firstIdx1, 1);
            c1--;
        }   
    }

    cout << S << "\n";

    return 0;
}