#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list, int n) {
    vector<int> v;
    for(int i = 0; i < num_list.size(); i++) {
        int k = num_list[i];
        if(i % n == 0) v.push_back(k);
    }
    
    return v;
}