#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long result = 0;
    int n2 = 2, n3 = 3;
    
    if(n <= 3) return n;
    for(int i = 4; i <= n; ++i) {
        result = (n2 + n3) % 1234567;
        n2 = n3;
        n3 = result;
    }
    
    return result;
}