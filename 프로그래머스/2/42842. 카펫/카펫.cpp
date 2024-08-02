#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int sum = brown + yellow;
    vector<int> v;
    for(int i = 3; i <= sum / 2; i++) {
        int n = sum / i;
        
        if(sum % i == 0) {
            if((n - 2) * (i - 2) == yellow) {
                v.push_back(n);
                v.push_back(i);
                break;
            }
        }
    }
    
    return v;
}