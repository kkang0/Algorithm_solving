#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> result;
bool visited[10001];
bool flag;

void dfs(string start, int cnt, vector<vector<string>> tickets) {
    result.push_back(start);
    
    if(cnt == tickets.size()) flag = true;
    
    for(int i = 0; i < tickets.size(); i++) {
        if(tickets[i][0] == start && !visited[i]) {
            visited[i] = true;
            dfs(tickets[i][1], cnt + 1, tickets);
            
            if(!flag) {
                result.pop_back();
                visited[i] = false;
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    
    dfs("ICN", 0, tickets);
    
    return result;
}