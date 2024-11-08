#include <cmath>
using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    
    for (int x = 1; x <= r2; x++) {
        int maxY = (int)sqrt((long long)r2 * r2 - (long long)x * x);
        int minY = (x < r1) ? (int)ceil(sqrt((long long)r1 * r1 - (long long)x * x)) : 0;
        
        answer += (maxY - minY + 1);
    }
    
    return answer * 4;
}