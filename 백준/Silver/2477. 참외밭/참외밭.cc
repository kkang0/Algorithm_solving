#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    cin >> K;
    vector<int> dir(6);
    vector<int> len(6);
    for(int i = 0; i < 6; i++) {
        cin >> dir[i] >> len[i];
    }

    int maxW= 0;
    int maxH = 0;
    int idxW = 0;
    int idxH = 0;

    for(int i = 0; i < 6; i++) {
        if(dir[i] == 1 || dir[i] == 2) {
            if(maxW < len[i]) {
                maxW = len[i];
                idxW = i;
            }
        } else {
            if(maxH < len[i]) {
                maxH = len[i];
                idxH = i;
            }
        }
    }

    int minW = abs(len[(idxH + 5) % 6] - len[(idxH + 1) % 6]);
    int minH = abs(len[(idxW + 5) % 6] - len[(idxW + 1) % 6]);

    int result = (maxW * maxH) - (minW * minH);
    cout << result * K << '\n';

    return 0;
}