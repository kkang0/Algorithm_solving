#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> sides) {
    sort(sides.begin(), sides.end());
    int a = sides[0];
    int b = sides[1];
    int c = sides[2];
    
    return a + b > c ? 1 : 2;
}