#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    for(int T = 0; T < t; T++) {
        int n;
        cin >> n;

        vector<int> nums(n);
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        long long result = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(i == j) continue;
                result += gcd(nums[i], nums[j]);
            }
        }

        cout << result << "\n";
    }

    return 0;
}