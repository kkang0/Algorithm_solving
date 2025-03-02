#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n, x;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    cin >> x;

    int start = 0, end = n - 1, result = 0;
    while(start < end) {
        int sum = v[start] + v[end];
        if(sum < x) {
            start++;
        }
        else if(sum > x) {
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