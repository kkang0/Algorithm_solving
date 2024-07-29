#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool areParallel(vector<int> p1, vector<int> p2, vector<int> p3, vector<int> p4) {
    int dx1 = p2[0] - p1[0];
    int dy1 = p2[1] - p1[1];
    int dx2 = p4[0] - p3[0];
    int dy2 = p4[1] - p3[1];
    
    return dx1 * dy2 == dy1 * dx2;
}

int solution(vector<vector<int>> dots) {
    return 
    (areParallel(dots[0], dots[1], dots[2], dots[3]) ||
    areParallel(dots[0], dots[2], dots[1], dots[3]) ||
    areParallel(dots[0], dots[3], dots[1], dots[2])) ? 1 : 0;
}
