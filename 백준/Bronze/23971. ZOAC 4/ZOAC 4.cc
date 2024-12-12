#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
    double H, W, N, M;
    cin >> H >> W >> N >> M;

    double h, w;
    h = ceil(H / (N + 1));
    w = ceil(W / (M + 1));

    cout << int(h * w) << endl;

    return 0;
}