#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int result = 0;
    
    while(n >= a) {
        int r = n / a;
        int d = n % a;
        result += r * b;
        n = r * b + d;
    }
    
    return result;
}