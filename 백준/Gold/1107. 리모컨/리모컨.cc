#include <iostream>
#include <cmath>
using namespace std;

int N, M;
int button[11];

bool button_set(int n) {
    string s = to_string(n);
    for(int i = 0; i < s.size(); i++) {
        if(button[s[i] - '0'] == 1) return false;
    }

    return true;
}

int main(void) {
    cin >> N;
    cin >> M;

    int ch = 100;
    if(M != 0) {
        for(int i = 0; i < M; i++) {
            int b;
            cin >> b;
            button[b] = 1;
        }
    }

    int result = abs(ch - N);

    for(int i = 0; i <= 1000000; i++) {
        if(button_set(i)) {
            int cnt = abs(N - i) + to_string(i).length();
            result = min(result, cnt);
        }
    }

    cout << result << endl;

    return 0;
}