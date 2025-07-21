#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int M;
    cin >> M;
    vector<char> s;
    s.resize(M);
    for(int i = 0; i < M; i++) {
        cin >> s[i];
    }

    int cnt = 0;
    int result = 0;
    for(int i = 1; i < M - 1;) {
        if(s[i - 1] == 'I' && s[i] == 'O' && s[i + 1] == 'I') {
            cnt++;
            if(cnt == N) {
                result++;
                cnt--;
            }
            i += 2;
        } else {
            cnt = 0;
            i++;
        }
    }

    cout << result << '\n';

    return 0;
}