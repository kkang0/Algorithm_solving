#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(void) {
    int N, S;
    cin >> N >> S;

    vector<int> v(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }

    int start = 0, end = 0, sum = 0, result = INT_MAX;
    while(start <= end) {
        if(sum >= S) {
            result = min(result, end - start);
            sum -= v[start++];
        } else if(end == N) break;
        else sum += v[end++];
    }

    if(result == INT_MAX) cout << 0 << endl;
    else cout << result << endl;

    return 0;
}