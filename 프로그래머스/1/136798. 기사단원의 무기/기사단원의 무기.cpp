#include <string>
#include <vector>

using namespace std;

int divisor_count(int n) {
    int divisionCount = 0;
    
    for(int i = 1; i <= n; i++) {
        if(n % i == 0) {
            divisionCount++;
        }
    }
    
    return divisionCount;
}

int solution(int number, int limit, int power) {
    int sum = 0;
    
    for(int i = 1; i <= number; i++) {
        int count = 1;
        for(int j = 1; j <= i / 2; j++) {
            if(i % j == 0) count++;
        }
        
        if(count > limit) count = power;
        sum += count;
    }
    
    return sum;
}
