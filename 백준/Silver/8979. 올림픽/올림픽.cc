#include <iostream>
using namespace std;

int medal[1001][4];
int main() {
    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int num, g, s, b;
        cin >> num >> g >> s >> b;
        medal[num][0] = g;
        medal[num][1] = s;
        medal[num][2] = b;
    }

    int rank = 1;
    for (int i = 1; i <= N; i++) {
        if (i == K) continue;

        if (medal[i][0] > medal[K][0]) rank++;
        else if (medal[i][0] == medal[K][0] && medal[i][1] > medal[K][1]) rank++;
        else if (medal[i][0] == medal[K][0] && medal[i][1] == medal[K][1] && medal[i][2] > medal[K][2]) rank++;
    }

    cout << rank << "\n";
    return 0;
}