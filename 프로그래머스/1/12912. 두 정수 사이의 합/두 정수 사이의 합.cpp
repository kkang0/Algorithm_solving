#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int a, int b) {
    long long sum = 0;
    int tmp;
    if (a > b) swap(a, b);
    
    for(int i = a; i <= b; i++) {
        sum += i;
    }
    
    return sum;
}