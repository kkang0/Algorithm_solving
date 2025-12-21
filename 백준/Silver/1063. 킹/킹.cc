#include <iostream>
#include <map>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string king, stone;
    int N;
    cin >> king >> stone >> N;

    int kx = king[0] - 'A';
    int ky = king[1] - '1';
    int sx = stone[0] - 'A';
    int sy = stone[1] - '1';

    map<string, pair<int, int>> dir = {
        {"R", {1, 0}},
        {"L", {-1, 0}},
        {"B", {0, -1}},
        {"T", {0, 1}},
        {"RT", {1, 1}},
        {"LT", {-1, 1}},
        {"RB", {1, -1}},
        {"LB", {-1, -1}}
    };

    while(N--) {
        string d;
        cin >> d;

        int dx = dir[d].first;
        int dy = dir[d].second;

        int nkx = kx + dx;
        int nky = ky + dy;

        if(nkx < 0 || nky < 0 || nkx >= 8 || nky >= 8) continue;
        if(nkx == sx && nky == sy) {
            int nsx = sx + dx;
            int nsy = sy + dy;

            if(nsx < 0 || nsy < 0 || nsx >= 8 || nsy >= 8) continue;
            sx = nsx;
            sy = nsy;
        }

        kx = nkx;
        ky = nky;
    }

    cout << char(kx + 'A') << char(ky + '1') << '\n';
    cout << char(sx + 'A') << char(sy + '1') << '\n';

    return 0;
}