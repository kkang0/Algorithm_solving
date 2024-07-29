#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
    return a > b;
}

vector<int> solution(vector<int> emergency) {
    vector<int> v = emergency;
    vector<int> result;
    sort(v.begin(), v.end(), compare);
    
    for(int i = 0; i < emergency.size(); i++) {
        for(int j = 0; j < v.size(); j++) {
            if(v[j] == emergency[i]) result.push_back(j + 1);
        }
    }
    
    return result;
}