#include <iostream>
using namespace std;

int main(void) {
    int N;
    cin >> N;
    
    for(int i = 1; i < N; i++) {
        int num = i;
        int sum = i;

        while(num != 0) {
            sum += num % 10;
            num /= 10;
        }

        if(sum == N) {
            cout << i << '\n';
            return 0;
        }
    }

    cout << 0 << endl;

    return 0;
}