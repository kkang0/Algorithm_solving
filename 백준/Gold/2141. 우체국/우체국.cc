#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int N;
    cin >> N;
    
    long long psum = 0;
    vector<pair<int, int>> v;
    for(int i = 0; i < N; i++) {
        long long x, a;
        cin >> x >> a;
        v.push_back({x, a});
        psum += a;
    }

    sort(v.begin(), v.end());
    long long result = 0;
    for(pair<int, int> p: v) {
        result += p.second;
        if(result >= (psum + 1)/2) {
            cout << p.first << endl;
            return 0;
        }
    }

    return 0;
}