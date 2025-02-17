#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int N;
    cin >> N;

    vector<int> budget(N);
    for(int i = 0; i < N; i++) {
        cin >> budget[i];
    }

    sort(budget.begin(), budget.end());

    int M;
    cin >> M;

    int start = 0;
    int end = budget[N - 1];
    int sum, result;

    while(start <= end) {
        sum = 0;
        int mid = (start + end) / 2;
        
        for(int i = 0; i < N; i++) {
            sum += min(budget[i], mid);
        }

        if(sum <= M) {
            result = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    cout << result << endl;

    return 0;
}