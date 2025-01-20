#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int N;
vector<vector<int>> v;

int main(void) {
    cin >> N;
    v.assign(N, vector<int>(N));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> v[i][j];
        }
    }

    vector<int> team(N, 0);
    for(int i = 0; i < N / 2; i++) {
        team[i] = 1;
    }

    sort(team.begin(), team.end());
    int result = INT_MAX;

    do {
        vector<int> start, link;

        for(int i = 0; i < N; i++) {
            if(team[i] == 1) {
                start.push_back(i);
            } else link.push_back(i);
        }

        int start_sum = 0;
        int link_sum = 0;

        for(int i = 0; i < N / 2; i++) {
            for(int j = i + 1; j < N / 2; j++) {
                start_sum += v[start[i]][start[j]] + v[start[j]][start[i]];
                link_sum += v[link[i]][link[j]] + v[link[j]][link[i]];
            }
        }

        result = min(result, abs(start_sum - link_sum));
    } while(next_permutation(team.begin(), team.end()));


    cout << result << endl;

    return 0;
}