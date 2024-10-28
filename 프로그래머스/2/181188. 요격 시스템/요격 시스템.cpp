#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(vector<int> a, vector<int> b) {
    if(a[1] == b[1]) return a[0] < b[0];
    return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 1;
    
    sort(targets.begin(), targets.end(), compare);
    
    int e = targets[0][1];
    
    for(int i = 1; i < targets.size(); i++) {
        if(targets[i][0] < e) continue;
        answer++;
        e = targets[i][1];
    }
    
    return answer;
}