#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int N;
    cin >> N;

    vector<int> nums(N);
    for(int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    int result = 0;
    for(int i = 0; i < N; i++) {
        int num = nums[i];
        int left = 0;
        int right = N - 1;

        while(left < right) {
            int sum = nums[left] + nums[right];
            if(sum == num) {
                if(left != i && right != i) {
                    result++;
                    break;
                } else if(left == i) left++;
                else if(right == i) right--;
            } else if(sum < num) left++;
            else right--;
        }
    }

    cout << result << "\n";

    return 0;
}