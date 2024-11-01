#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> v(n + 1);
    for(int i = 0; i < edge.size(); i++) {
        v[edge[i][0]].push_back(edge[i][1]);
        v[edge[i][1]].push_back(edge[i][0]);
    }
    
    vector<bool> visited(n + 1, false);
    vector<int> result(n + 1, 0);
    queue<int> q;
    q.push(1);
    visited[1] = true;
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        
        for(int i = 0; i < v[node].size(); i++) {
            if(!visited[v[node][i]]) {
                int cnt = result[node] + 1;
                visited[v[node][i]] = true;
                result[v[node][i]] = cnt;
                q.push(v[node][i]);
            }
        }
    }
    
    int answer = 0;
    sort(result.begin(), result.end(), greater<int>());
    for(int cnt: result) {
        if(result[0] != cnt) break;
        answer++;
    }
    
    return answer;
}