#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, int s) {
    if(s < n) return {-1};
    
    vector<int> result(n, s / n);
    
    int d = s % n;
    for(int i = 0; i < d; i++) {
        result[n - 1 - i]++;
    }
    
    return result;
}