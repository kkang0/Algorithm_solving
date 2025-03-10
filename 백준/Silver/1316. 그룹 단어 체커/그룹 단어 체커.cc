#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int N;
    cin >> N;

    int cnt = 0;
    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;

        bool flag = true;

        for(int j = 0; j < s.size(); j++) {
            for(int k = 0; k < j; k++) {
                if(s[j] != s[j - 1] && s[j] == s[k]) {
                    flag = false;
                    break;
                }
            }
        }

        if(flag) cnt++;
    }

    cout << cnt << endl;

    return 0;
}