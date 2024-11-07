#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> order) {
    stack<int> stk;
    int result = 0;
    
    for(int i = 1; i <= order.size(); i++) {
        stk.push(i);
        
        while(!stk.empty() && stk.top() == order[result]) {
            stk.pop();
            result++;
        }
    }
    
    return result;
}