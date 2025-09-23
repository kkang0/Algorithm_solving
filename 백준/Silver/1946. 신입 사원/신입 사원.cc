#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        vector<pair<int, int>> nums(N);
        for(int i = 0; i < N; i++) {
            cin >> nums[i].first >> nums[i].second;
        }

        sort(nums.begin(), nums.end());

        int min_score = nums[0].second;
        int result = 1;
        for(auto& p: nums) {
            if(min_score > p.second) {
                result++;
                min_score = p.second;
            }
        }

        cout << result << '\n';
    }

    return 0;
}