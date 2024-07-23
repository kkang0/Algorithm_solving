#include <vector>
using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    int value = 1;
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;

    while (value <= n * n) {
        for (int i = left; i <= right && value <= n * n; ++i) {
            matrix[top][i] = value++;
        }
        top++;

        for (int i = top; i <= bottom && value <= n * n; ++i) {
            matrix[i][right] = value++;
        }
        right--;

        for (int i = right; i >= left && value <= n * n; --i) {
            matrix[bottom][i] = value++;
        }
        bottom--;

        for (int i = bottom; i >= top && value <= n * n; --i) {
            matrix[i][left] = value++;
        }
        left++;
    }

    return matrix;
}
