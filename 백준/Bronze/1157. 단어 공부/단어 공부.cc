#include <iostream>
using namespace std;

int main(void) {
    string s;
    cin >> s;

    int num[26] = {0, };

    for(int i = 0; i < s.size(); i++) {
        s[i] = toupper(s[i]);
        num[s[i] - 65]++;
    }

    int max = 0;
    int idx = -1;
    for(int i = 0; i < 26; i++) {
        if(max < num[i]) {
            max = num[i];
            idx = i;
        }
    }

    for(int i = 0; i < 26; i++) {
        if(i == idx) continue;
        if(num[i] == max) {
            cout << "?" << endl;
            return 0;
        }
    }

    cout << (char)(idx + 65) << endl;

    return 0;
}