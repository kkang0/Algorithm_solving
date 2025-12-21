#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W;
    cin >> H >> W;

    vector<string> sky(H);
    for(int i = 0; i < H; i++) {
        cin >> sky[i];
    }

    for(int i = 0; i < H; i++) {
        int last = -1;
        for(int j = 0; j < W; j++) {
            if(sky[i][j] == 'c') {
                cout << 0 << " ";
                last = j;
            } else {
                if(last == -1) cout << -1 << " ";
                else cout << j - last << " ";
            }
        }
        cout << '\n';
    }

    return 0;
}