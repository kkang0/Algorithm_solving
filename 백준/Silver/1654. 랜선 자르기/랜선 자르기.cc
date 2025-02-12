#include <iostream>
#include <climits>
using namespace std;

long long K, N, result;
long long lan[10001];

int main(void) {
    cin >> K >> N;

    long long max_num = INT_MAX;
    for(int i = 0; i < K; i++) {
        cin >> lan[i];
        max_num = max(max_num, lan[i]);
    }

    long long left = 1;
    long long right = max_num;
    long long mid;

    while(left <= right) {
        mid = (left + right) / 2;

        long long sum = 0;
        for(int i = 0; i < K; i++) {
            sum += lan[i] / mid;
        }

        if(sum >= N) {
            left = mid + 1;
            result = max(result, mid);
        } else {
            right = mid - 1;
        }
    }

    cout << right << endl;

    return 0;
}