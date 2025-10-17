#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N;
    vector<int> weight(N);
    for(int i = 0; i < N; i++) cin >> weight[i];

    cin >> M;
    vector<int> boxes(M);
    for(int i = 0; i < M; i++) cin >> boxes[i];

    sort(weight.begin(), weight.end(), greater<int>());
    sort(boxes.begin(), boxes.end(),greater<int>());

    if(boxes[0] > weight[0]) {
        cout << -1 << '\n';
        return 0;
    }

    int time = 0;
    vector<int> crane_pos(N, 0);
    vector<bool> visited(M, false);
    int box_idx = 0;
    
    while(box_idx < M) {
        time++;

        for(int i = 0; i < N; i++) {
            for(int j = crane_pos[i]; j < M; j++) {
                if(!visited[j] && weight[i] >= boxes[j]) {
                    visited[j] = true;
                    box_idx++;
                    crane_pos[i] = j + 1;
                    break;
                }

                if(j == M - 1) {
                    crane_pos[i] = M;
                }
            }
        }
    }

    cout << time << '\n';

    return 0;
}