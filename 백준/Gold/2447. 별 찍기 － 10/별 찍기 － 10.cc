#include <iostream>
using namespace std;

void print(int x, int y, int n) {
    if((x / n) % 3 == 1 && (y / n) % 3 == 1) {
        cout << ' ';
    } else {
        if(n == 1) cout << '*';
        else print(x, y, n / 3);
    }
}


int main(void) {
    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            print(i, j, N);
        }
        cout << "\n";
    }

    return 0;
}