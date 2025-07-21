#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        string p;
        cin >> p;
        int n;
        cin >> n;
        string s;
        cin >> s;

        deque<int> dq;
        string num = "";
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == ',' || s[i] == ']') {
                if(num != "") dq.push_back(stoi(num));
                num = "";
            } else num += s[i];
        }

        bool rev = false;
        bool err = false;

        for(int i = 0; i < p.size(); i++) {
            if(p[i] == 'R') rev = !rev;
            else if(p[i] == 'D') {
                if(dq.empty()) {
                    err = true;
                    break;
                } else {
                    if(rev) dq.pop_back();
                    else dq.pop_front();
                }
            }
        }

        if(err) cout << "error" << '\n';
        else {
            if(rev) reverse(dq.begin(), dq.end());
            cout << '[';
            for(int i = 0; i < dq.size(); i++) {
                if(i == dq.size() - 1) cout << dq[i];
                else cout << dq[i] << ',';
            }
            cout << ']' << '\n';
        }

    }

    return 0;
}