#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int n = triangle.size();

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                triangle[i][j] += triangle[i-1][j];
            } else if (j == i) {
                triangle[i][j] += triangle[i-1][j-1];
            } else {
                triangle[i][j] += max(triangle[i-1][j], triangle[i-1][j-1]);
            }
        }
    }

    int maxSum = 0;
    for (int j = 0; j < n; j++) {
        maxSum = max(maxSum, triangle[n-1][j]);
    }

    return maxSum;
}