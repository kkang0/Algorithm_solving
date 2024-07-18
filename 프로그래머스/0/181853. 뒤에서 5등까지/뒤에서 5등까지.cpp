#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> num_list) {
    sort(num_list.begin(), num_list.end());
    
    vector<int> result;
    for(int i = 0; i < 5; i++) {
        int num = num_list[i];
        result.push_back(num);
    }
    
    return result;
}