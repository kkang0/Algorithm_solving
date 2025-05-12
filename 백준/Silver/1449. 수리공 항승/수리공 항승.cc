#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, L;
    cin >> N >> L;

    vector<int> pipe(N);
    for(int i = 0; i < N; i++) {
        cin >> pipe[i];
    }

    sort(pipe.begin(), pipe.end());

    int tape = 0;
    int cover_range = 0;
    for(int i = 0; i < N; i++) {
        if(pipe[i] >= cover_range) {
            cover_range = pipe[i] + L;
            tape++;
        }
    }

    cout << tape << "\n";

    return 0;
}