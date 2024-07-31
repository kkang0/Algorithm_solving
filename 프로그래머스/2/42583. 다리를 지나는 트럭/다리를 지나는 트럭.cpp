#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> q;
    int time = 0;
    int weight_sum = 0;
    int idx = 0;
    
    while(1) {
        int cur_weight = truck_weights[idx];
        
        if(idx == truck_weights.size()) {
            time += bridge_length;
            break;
        }
        
        if(q.size() == bridge_length) {
            weight_sum -= q.front();
            q.pop();
        }
        
        if(cur_weight + weight_sum <= weight) {
            weight_sum += cur_weight;
            q.push(cur_weight);
            idx++;
        } else {
            q.push(0);
        }
        
        time++;
    }
    
    return time;
}