#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;
    int mid = total / num;
    int n = num / 2;
    
    int idx = 0;
    if(num % 2 == 0) idx = mid - n + 1;
    else idx = mid - n;
    
    for(int i = idx; i <= mid + n; i++) {
        answer.push_back(i);
    }
    
    return answer;
}