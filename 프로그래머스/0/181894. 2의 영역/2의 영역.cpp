#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> v;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == 2) v.push_back(i);
    }
    
    if(v.empty()) {
        return {-1};
    }
    
    int s = v[0];
    int e = v[v.size() - 1];
    return vector<int>(arr.begin() + s, arr.begin() + e + 1);
}