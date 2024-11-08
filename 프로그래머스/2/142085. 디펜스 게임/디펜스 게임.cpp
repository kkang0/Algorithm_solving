#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    priority_queue<int> pq;
    int result = 0;
    
    for (int i = 0; i < enemy.size(); i++) {
        n -= enemy[i];
        pq.push(enemy[i]);
        result++;
        
        if (n < 0) {
            if (k > 0) {
                n += pq.top();
                pq.pop();
                k--;
            } else {
                result--;
                break;
            }
        }
    }
    
    return result;
}