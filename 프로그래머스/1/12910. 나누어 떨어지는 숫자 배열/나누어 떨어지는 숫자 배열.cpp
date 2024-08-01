#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> v;
    for(int i: arr) {
        if(i % divisor == 0) v.push_back(i);
    }
    
    if(v.empty()) v.push_back(-1);
    
    sort(v.begin(), v.end());
    
    return v;
}