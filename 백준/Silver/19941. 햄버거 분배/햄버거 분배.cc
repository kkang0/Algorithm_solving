#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    string s;
    cin >> s;

    vector<bool> eaten(N, false);
    int result = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'P') {
            bool flag = false;
            for(int j = max(0, i - K); j < i; j++) {
                if(s[j] == 'H' && !eaten[j]) {
                    eaten[j] = true;
                    flag = true;
                    result++;
                    break;
                }
            }

            if(!flag) {
                for(int j = i + 1; j <= min(N - 1, i + K); j++) {
                    if(s[j] == 'H' && !eaten[j]) {
                        eaten[j] = true;
                        result++;
                        break;
                    }
                }
            }
        }
    }

    cout << result << "\n";

    return 0;
}