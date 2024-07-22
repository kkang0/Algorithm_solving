#include <string>
#include <vector>

using namespace std;

int solution(int a, int d, vector<bool> included) {
    int sum = 0;
    for(int i = 0; i < included.size(); i++) {
        if(included[i]) {
            sum += a + i * d;
        }
    }
    
    return sum;
}