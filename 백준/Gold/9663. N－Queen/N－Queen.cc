#include <iostream>
#include <cmath>
using namespace std;

int col[16];
int N;
int result;

void nqueen(int x) {
    if(x == N) result++;
    else {
        for(int i = 0; i < N; i++) {
            col[x] = i;
            bool flag = true;
            for(int j = 0; j < x; j++) {
                if(col[x] == col[j] || abs(col[x] - col[j]) == x - j) {
                    flag = false;
                    break;
                }
            }

            if(flag) nqueen(x + 1);
        }
    }
}

int main(void) {
    cin >> N;

    nqueen(0);

    cout << result << endl;

    return 0;
}