#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<int> nums(N);
    for(int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    int result = 0;
    for(int i = N - 1; i > 0; i--) {
        if(nums[i] <= nums[i - 1]) {
            int num = nums[i - 1] - nums[i] + 1;
            nums[i - 1] -= num;
            result += num;
        }
    }

    cout << result << '\n';

    return 0;
}