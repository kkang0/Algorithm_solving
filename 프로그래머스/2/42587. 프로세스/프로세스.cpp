#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    priority_queue<int> pq;
    queue<pair<int, int>> q;
    for(int i = 0; i < priorities.size(); i++) {
        q.push({i, priorities[i]});
        pq.push(priorities[i]);
    }
    
    int result = 0;
    int count = 1;
    while(1) {
        pair<int, int> qfront = q.front();
        q.pop();
        
        if(qfront.second == pq.top()) {
            if(qfront.first == location) {
                result = count;
                break;
            } else {
                pq.pop();
                count++;
            }
        } else {
            q.push({qfront.first, qfront.second});
        }
    }
    
    return result;
}