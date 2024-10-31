#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> result;
    for(int n = 0; n < commands.size(); n++) {
        int i = commands[n][0] - 1;
        int j = commands[n][1];
        int k = commands[n][2];
        
        vector<int> v(array.begin() + i, array.begin() + j);
        sort(v.begin(), v.end());
        result.push_back(v[k - 1]);
    }
    
    return result;
}