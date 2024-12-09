#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int max = 1;
    int m = 6;
    int num = 1;
    while(N > max) {
        max += m;
        m += 6;
        num++;
    }

    cout << num << endl;

    return 0;
}