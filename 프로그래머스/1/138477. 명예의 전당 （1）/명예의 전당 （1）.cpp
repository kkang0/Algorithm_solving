#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> result;
    vector<int> v;
    for(int i = 0; i < score.size(); i++) {
        int s = score[i];
        v.push_back(s);
        sort(v.begin(), v.end(), greater<int>());
        
        if(v.size() > k) v.pop_back();
        
        result.push_back(v[v.size() - 1]);
    }
    
    return result;
}