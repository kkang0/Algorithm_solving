#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int solution(vector<vector<int>> dots) {
    sort(dots.begin(), dots.end());
    int x = abs(dots[0][0] - dots[2][0]);
    int y = abs(dots[0][1] - dots[1][1]);
    
    return x * y;
}