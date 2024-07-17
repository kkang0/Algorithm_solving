#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int sum = 0;
    if(n % 2 != 0) {
        for(int i = n; i > 0; i -= 2) {
            sum += i;
        }
    } else {
        for(int i = n; i > 1; i -= 2) {
            sum += i * i;
        }
    }
    
    return sum;
}