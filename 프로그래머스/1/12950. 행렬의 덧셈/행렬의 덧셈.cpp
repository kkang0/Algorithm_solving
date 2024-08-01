#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> result;
    vector<int> v;
    int sum;
    for(int i = 0; i < arr1.size(); i++) {
        v.clear();
        for(int j = 0; j < arr1[i].size(); j++) {
            sum = arr1[i][j] + arr2[i][j];
            v.push_back(sum);
        }
        
        result.push_back(v);
    }
    
    return result;
}