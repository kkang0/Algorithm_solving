#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    
    for(int i = 0; i < queries.size(); i++) {
        int s = queries[i][0];
        int e = queries[i][1];
        int k = queries[i][2];
        int min = 1000001;
        bool find = false;
        
        for(int j = s; j <= e; j++) {
            if(k < arr[j] && arr[j] < min) {
                min = arr[j];
                find = true;
            }
        }
        
        if(find) answer.push_back(min);
        else answer.push_back(-1);
    }
    
    return answer;
}