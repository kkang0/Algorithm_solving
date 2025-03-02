#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int N, M;
    cin >> N;
    cin >> M;

    vector<int> v(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    int start = 0, end = N - 1, result = 0;

    while(start < end) {
        int sum = v[start] + v[end];

        if(sum < M) {
            start++;
        }
        else if(sum > M) {
            end--;
        }
        else {
            result++;
            start++;
            end--;
        }
    }

    cout << result << endl;

    return 0;
}