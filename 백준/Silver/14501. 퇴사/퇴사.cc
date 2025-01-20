#include <iostream>
using namespace std;

int N;
int Ti[16];
int Pi[16];
int result[16];

void dp() {
    int dl;
    for(int i = N; i > 0; i--) {
        dl = i + Ti[i];
        if(dl > N + 1) result[i] = result[i + 1];
        else result[i] = max(result[i + 1], result[dl] + Pi[i]);

    }
}

int main(void) {
    cin >> N;

    for(int i = 1; i <= N; i++) {
        cin >> Ti[i] >> Pi[i];
    }

    dp();

    cout << result[1] << endl;

    return 0;
}