#include <iostream>
#include <string>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int cnt = 0;
    int num = 665;

    while(cnt < N) {
        num++;
        if(to_string(num).find("666") != string::npos) cnt++;
    }

    cout << num << '\n';

    return 0;
}