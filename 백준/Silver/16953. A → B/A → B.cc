#include <iostream>
#include <string>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;

    int cnt = 1;
    while(a != b) {
        if(b < a) {
            cnt = -1;
            break;
        }

        if(b % 2 == 0) {
            b /= 2;
            cnt++;
        } else if(b % 10 == 1) {
            b /= 10;
            cnt++;
        } else {
            cnt = -1;
            break;
        }
    }

    cout << cnt << endl;

    return 0;
}