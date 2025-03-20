#include <iostream>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int M;
    cin >> M;

    bool arr[21] = {false, };
    for(int i = 0; i < M; i++) {
        string s;
        int x;
        cin >> s;

        if(s == "add") {
            cin >> x;
            arr[x] = true;
        } else if(s == "remove") {
            cin >> x;
            arr[x] = false;
        } else if(s == "check") {
            cin >> x;
            cout << (arr[x] ? 1 : 0) << "\n";
        } else if(s == "toggle") {
            cin >> x;
            if(arr[x]) arr[x] = false;
            else arr[x] = true;
        } else if(s == "all") {
            fill_n(arr, 21, true);
        } else if(s == "empty") {
            fill_n(arr, 21, false);
        }
    }

    return 0;
}