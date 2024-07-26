#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int count = 1;
    while(1) {
        if((count % n == 0) && (count % 6 == 0)) break;
        count++;
    }
    
    return count / 6;
}