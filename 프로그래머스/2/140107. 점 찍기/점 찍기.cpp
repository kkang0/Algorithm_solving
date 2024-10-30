#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    
    for(long long i = 0; i <= d; i += k) {
        int y = sqrt(1LL * d * d - 1LL * i * i);
        answer += y / k + 1;
    }
    return answer;
}