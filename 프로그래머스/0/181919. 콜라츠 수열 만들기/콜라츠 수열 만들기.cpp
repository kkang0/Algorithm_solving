#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> v;
    
    v.push_back(n);
    while(n != 1) {
        if(n % 2 == 0) {
            n /= 2;
            v.push_back(n);
        } else {
            n = 3 * n + 1;
            v.push_back(n);
        }
    }
    
    return v;
}