#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> sides) {
    sort(sides.begin(), sides.end());
    int sum = sides[0] + sides[1];
    
    int result = 0;
    int dif = sides[1] - sides[0] + 1;
    for(int i = dif; i <= sides[1]; i++) {
        result++;
    }
    for(int i = sides[1] + 1; i < sum; i++) {
        result++;
    }
    
    return result;
    
}