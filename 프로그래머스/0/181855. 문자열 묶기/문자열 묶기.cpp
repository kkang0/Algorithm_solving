#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> strArr) {
    vector<int> size(31);
    int result = 0;
    for(int i = 0; i < strArr.size(); i++) {
        size[strArr[i].size()]++;
        result = max(result, size[strArr[i].size()]);
    }
    
    return result;
}