#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>
using namespace std;

int N;
vector<int> nums;

int mean() {
    double result = 0;
    for(int i = 0; i < N; i++) result += nums[i];
    return (int)round(result / N);
}

int median() {
    vector<int> tmp = nums;
    sort(tmp.begin(), tmp.end());

    return tmp[N / 2];
}

int mode() {
    unordered_map<int, int> um;
    int max_num = -1;
    for(int i = 0; i < N; i++) {
        um[nums[i]]++;
        if(um[nums[i]] > max_num) {
            max_num = um[nums[i]];
        }
    }

    vector<int> candidates;
    for(auto& p: um) {
        if(p.second == max_num) {
            candidates.push_back(p.first);
        }
    }

    sort(candidates.begin(), candidates.end());

    if(candidates.size() == 1) return candidates[0];
    else return candidates[1];
}

int range() {
    int max_num = *max_element(nums.begin(), nums.end());
    int min_num = *min_element(nums.begin(), nums.end());

    return max_num - min_num;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    nums.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    cout << mean() << '\n';
    cout << median() << '\n';
    cout << mode() << '\n';
    cout << range() << '\n';

    return 0;
}