#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    string bomb;
    cin >> bomb;

    string result = "";
    for(int i = 0; i < s.size(); i++) {
        result += s[i];

        if(result.size() >= bomb.size()) {
            bool flag = true;
            for(int j = 0; j < bomb.size(); j++) {
                if(result[result.size() - bomb.size() + j] != bomb[j]) {
                    flag = false;
                    break;
                }
            }

            if(flag) {
                result.erase(result.end() - bomb.size(), result.end());
            }
        }

    }

    if(result.empty()) cout << "FRULA" << '\n';
    else cout << result << '\n';

    return 0;
}