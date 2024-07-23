#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> query) {
    vector<int> v = arr;
    for (int i = 0; i < query.size(); i++) {
        if (i % 2 == 0) {
            v = vector<int>(v.begin(), v.begin() + query[i] + 1);
        } else {
            v = vector<int>(v.begin() + query[i], v.end());
        }
    }
    
    return v;
}
