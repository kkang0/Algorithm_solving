#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    
    int cnt = 0;
    
    while(pq.top() < K) {
        if(pq.size() < 2) return -1;
        
        int min1 = pq.top();
        pq.pop();
        int min2 = pq.top();
        pq.pop();
        int new_scoville = min1 + min2 * 2;
        pq.push(new_scoville);
        cnt++;
    }
    
    return cnt;
}