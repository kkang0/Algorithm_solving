#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, B;
    cin >> N >> M >> B;

    vector<vector<int>> height(N, vector<int>(M));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> height[i][j];
        }
    }

    int result_time = 1e9;
    int max_height = 0;
    for(int i = 0; i <= 256; i++) {
        int build = 0;
        int remove = 0;

        for(int j = 0; j < N; j++) {
            for(int k = 0; k < M; k++) {
                int h = height[j][k] - i;
                if(h > 0) remove += h;
                else if(h < 0) build -= h;
            }
        }

        if(remove + B >= build) {
            int time = remove * 2 + build;
            if(result_time >= time) {
                result_time = time;
                max_height = i;
            }
        }
    }

    cout << result_time << ' ' << max_height << '\n';

    return 0;
}