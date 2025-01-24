#include <iostream>
#include <cmath>
using namespace std;

int N, r, c;
int result;

void z(int x, int y, int n) {
    if(x == c && y == r) {
        cout << result << endl;
        return;
    }

    if(c < x + n && r < y + n && c >= x && r >= y) {
        z(x, y, n / 2);
        z(x + n / 2, y, n / 2);
        z(x, y + n / 2, n / 2);
        z(x + n / 2, y + n / 2, n / 2);
    } else result += n * n;
}

int main(void) {
    cin >> N >> r >> c;

    z(0, 0, pow(2, N));

    return 0;
}