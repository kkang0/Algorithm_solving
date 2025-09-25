#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string X;
    cin >> X;

    if(next_permutation(X.begin(), X.end())) cout << X << '\n';
    else cout << 0 << '\n';

    return 0;
}