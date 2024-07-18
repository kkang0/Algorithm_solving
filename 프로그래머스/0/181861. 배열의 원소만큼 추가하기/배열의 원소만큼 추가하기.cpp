#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> result;
    for(int i = 0; i < arr.size(); i++) {
        int num = arr[i];
        for(int j = 0; j < num; j++) {
            result.push_back(num);
        }
    }
    
    return result;
}