#include <iostream>
#include <algorithm>
using namespace std;

int N;
char candy[51][51];

int getMaxCnt() {
    int max_cnt = 1;
    for(int i = 0; i < N; i++) {
        int cnt = 1;

        for(int j = 1; j < N; j++) {
            if(candy[i][j] == candy[i][j - 1]) cnt += 1;
            else cnt = 1;
            max_cnt = max(cnt, max_cnt);
        }
        
        cnt = 1;
        for(int j = 1; j < N; j++) {
            if(candy[j][i] == candy[j - 1][i]) cnt += 1;
            else cnt = 1;
            max_cnt = max(cnt, max_cnt);
        }
    }

    return max_cnt;
}

int main(void) {
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> candy[i];
    }

    int result = 1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N - 1; j++) {
            if (candy[i][j] != candy[i][j + 1]) {
                swap(candy[i][j], candy[i][j + 1]);
                result = max(result, getMaxCnt());
                swap(candy[i][j], candy[i][j + 1]);
            }

            if (candy[j][i] != candy[j + 1][i]) {
                swap(candy[j][i], candy[j + 1][i]);
                result = max(result, getMaxCnt());
                swap(candy[j][i], candy[j + 1][i]);
            }
        }
    }

    cout << result << endl;
    return 0;
}