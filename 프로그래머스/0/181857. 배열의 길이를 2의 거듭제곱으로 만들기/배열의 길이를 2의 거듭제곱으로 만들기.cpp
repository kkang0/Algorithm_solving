#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    int len = 1;
    while(len < arr.size()) {
        len *= 2;
    }
    
    vector<int> result = arr;
    while(result.size() < len) {
        result.push_back(0);
    }
    
    return result;
}