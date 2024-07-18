#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int k) {
    int m = 1;
    vector<int> v;
    for(int i = k; i <= n; i = k * (++m)) {
        v.push_back(i);
    }
    
    return v;
}