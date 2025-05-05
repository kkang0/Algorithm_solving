#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    char ham[20001];
    cin >> ham;
    
    int result = 0;
    for(int i = 0; i < N; i++) {
        if(ham[i] == 'P') {
            for(int j = i - K; j <= i + K; j++) {
                if(j >= 0 && j < N && ham[j] == 'H') {
                    result++;
                    ham[j] = 'X';
                    break;
                }
            }
        }
    }

    cout << result << "\n";

    return 0;
}