#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> arr;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    arr.resize(N + 1, vector<int>(N + 1));
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> arr[i][j];
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1] + arr[i][j] - arr[i - 1][j - 1];
        }
    }

    for(int i = 0; i < M; i++) {
        int result = 0;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        result = arr[x2][y2] - (arr[x1 - 1][y2] + arr[x2][y1 - 1]) + arr[x1 - 1][y1 - 1];
        cout << result << '\n';
    }

    return 0;
}