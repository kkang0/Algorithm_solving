#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list, int n) {
    vector<int> v;
    for(int i = 0; i < n; i++) {
        int m = num_list[i];
        v.push_back(m);
    }
    
    return v;
}