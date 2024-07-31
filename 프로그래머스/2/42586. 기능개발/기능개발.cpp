#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    queue<int> q;
    int days;
    for(int i = 0; i < progresses.size(); i++) {
        int rest = 100 - progresses[i];
        if(rest % speeds[i] != 0) days = rest / speeds[i] + 1;
        else days = rest / speeds[i];
        q.push(days);
    }
    
    vector<int> result;
    int count = 1;
    int prev = q.front();
    q.pop();
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        if(prev < cur) {
            result.push_back(count);
            count = 1;
            prev = cur;
        } else {
            count++;
        }
    }
    
    result.push_back(count);
    
    return result;
}