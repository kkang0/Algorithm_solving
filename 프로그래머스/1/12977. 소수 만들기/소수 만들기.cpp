#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool isPrime(int num) {
    if(num <= 1) return false;
    for(int i = 2; i <= sqrt(num); i++) {
        if(num % i == 0) return false;
    }
    return true;
}

int solution(vector<int> nums) {
    sort(nums.begin(), nums.end());
    
    vector<bool> select(nums.size(), false);
    fill(select.begin(), select.begin() + 3, true);
    int cnt = 0;
    do {
        int sum = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            if(select[i]) {
                sum += nums[i];
            }
        }
        
        if(isPrime(sum)) cnt++;
        
    } while (prev_permutation(select.begin(), select.end()));
    
    return cnt;
}