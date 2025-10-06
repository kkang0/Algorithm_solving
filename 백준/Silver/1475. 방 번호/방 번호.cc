#include <iostream>
#include <algorithm>
using namespace std;

int nums[10];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string N;
    cin >> N;

    for(int i = 0; i < N.size(); i++) {
        int n = N[i] - '0';
        nums[n]++;
    }

    nums[6] = (nums[6] + nums[9] + 1) / 2;
    nums[9] = 0;

    int result = 0;
    for(int i = 0; i < 10; i++) {
        result = max(result, nums[i]);
    }

    cout << result << '\n';

    return 0;
}