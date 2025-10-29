#include <iostream>
using namespace std;

const int INF = 1e9;
int bottom[500001];
int top[500001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, H;
    cin >> N >> H;
    
    for(int i = 0; i < N; i++) {
        int h;
        cin >> h;
        if(i % 2 == 0) bottom[h]++;
        else top[h]++;
    }

    for(int i = H-1; i >= 1; i--) {
        bottom[i] += bottom[i + 1];
        top[i] += top[i + 1];
    }

    int min_c = INF;
    int cnt = 0;
    for(int i = 1; i <= H; i++) {
        int c = bottom[i] + top[H - i + 1];
        if(c < min_c) {
            min_c = c;
            cnt = 1;
        } else if(c == min_c) {
            cnt++;
        }
    }

    cout << min_c << ' ' << cnt << '\n';
    return 0;
}