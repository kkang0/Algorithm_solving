#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    map<int, int> m;
    for(int t: tangerine) {
        m[t]++;
    }
    
    vector<pair<int, int>> freq(m.begin(), m.end());
    sort(freq.begin(), freq.end(), compare);
    
    int sum = 0;
    int result = 0;
    for(auto a: freq) {
        sum += a.second;
        result++;
        if(sum >= k) break;
    }
    
    return result;
}