#include <iostream>
using namespace std;


long long mul(long long a, long long b, long long c) {
    if(b == 0) return 1;
    if(b % 2 == 0) {
        long long result = mul(a, b / 2, c);
        return result * result % c;
    } else {
        return mul(a, b - 1, c) * a % c;
    }
}

int main(void) {
    int A, B, C;
    cin >> A >> B >> C;

    cout << mul(A, B, C) << endl;

    return 0;
}