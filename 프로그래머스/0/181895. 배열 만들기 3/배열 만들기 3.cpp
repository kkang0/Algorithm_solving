#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> intervals) {
    vector<int> answer;
    for(int i = 0; i < intervals.size(); i++) {
        int a = intervals[i][0];
        int b = intervals[i][1];
        answer.insert(answer.end(), arr.begin() + a, arr.begin() + b + 1);
    }
    
    return answer;
}