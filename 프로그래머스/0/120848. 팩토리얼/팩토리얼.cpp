#include <string>
#include <vector>

using namespace std;

int fact(int num) {
    if(num == 0) return 1;
    return num * fact(num - 1);
}

int solution(int n) {
    int i = 1;
    while(fact(i) <= n) {
        i++;
    }
    
    return i - 1;
}