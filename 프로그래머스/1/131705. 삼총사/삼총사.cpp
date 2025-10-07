#include <string>
#include <vector>
using namespace std;

vector<int> nums;
vector<bool> visited;
int result;

void dfs(int idx, int sum, int cnt) {
    if(cnt == 3) {
        if(sum == 0) result++;
        return;
    }
    
    for(int i = idx; i < nums.size(); i++) {
        if(!visited[i]) {
            visited[i] = true;
            dfs(i + 1, sum + nums[i], cnt + 1);
            visited[i] = false;
        }
    }
}

int solution(vector<int> number) {
    nums = number;
    visited.resize(number.size(), false);
    
    dfs(0, 0, 0);
    
    return result;
}