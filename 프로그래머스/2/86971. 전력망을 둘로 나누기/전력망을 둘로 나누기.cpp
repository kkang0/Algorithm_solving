#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int bfs(vector<vector<int>>& v, int start, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int count = 0;
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        count++;
        
        for (int adj : v[cur]) {
            if (!visited[adj]) {
                visited[adj] = true;
                q.push(adj);
            }
        }
    }
    
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int min_diff = n;
    vector<vector<int>> v(n + 1);
    
    for (auto& wire : wires) {
        int v1 = wire[0];
        int v2 = wire[1];
        v[v1].push_back(v2);
        v[v2].push_back(v1);
    }
    
    for (auto& wire : wires) {
        int v1 = wire[0];
        int v2 = wire[1];
        
        v[v1].erase(remove(v[v1].begin(), v[v1].end(), v2), v[v1].end());
        v[v2].erase(remove(v[v2].begin(), v[v2].end(), v1), v[v2].end());
        
        vector<bool> visited(n + 1, false);
        int sub_size = bfs(v, v1, visited);
        
        int diff = abs(n - 2 * sub_size);
        min_diff = min(min_diff, diff);
        
        v[v1].push_back(v2);
        v[v2].push_back(v1);
    }
    
    return min_diff;
}
