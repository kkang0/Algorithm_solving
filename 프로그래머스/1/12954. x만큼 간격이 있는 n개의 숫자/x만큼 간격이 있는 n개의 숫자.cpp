#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> v;
    int sum = x;
    for(int i = 0; i < n; i++) {
        v.push_back(sum);
        sum += x;
    }
    
    return v;
}