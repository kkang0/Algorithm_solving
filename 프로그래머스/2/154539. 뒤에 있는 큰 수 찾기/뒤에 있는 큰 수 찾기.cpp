#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> numbers) {
    stack<int> stk;
    vector<int> result(numbers.size(), -1);
    
    for(int i = 0; i < numbers.size(); i++) {
        while(!stk.empty() && numbers[stk.top()] < numbers[i]) {
            result[stk.top()] = numbers[i];
            stk.pop();
        }
        
        stk.push(i);
    }
    
    return result;
}