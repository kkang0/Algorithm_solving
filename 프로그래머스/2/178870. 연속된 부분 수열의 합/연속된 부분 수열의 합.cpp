#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    int len_a = a.second - a.first;
    int len_b = b.second - b.first;
    
    if(len_a != len_b) return len_a < len_b;
    return a.first < b.first;
}

vector<int> solution(vector<int> sequence, int k) {
    vector<pair<int, int>> result;
    int start = 0, end = 0, sum = sequence[0];
    
    while(end < sequence.size()) {
        if(sum == k) result.push_back({start, end});
        
        if(sum <= k) {
            end++;
            if(end < sequence.size()) sum += sequence[end];
        } else {
            sum -= sequence[start];
            start++;
        }
    }
    
    sort(result.begin(), result.end(), compare);
    
    return {result[0].first, result[0].second};
}