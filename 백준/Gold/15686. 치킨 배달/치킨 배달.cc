#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;

int N, M;
int arr[51][51];
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
int result = INT_MAX;

int main(void) {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(arr[i][j] == 1) house.push_back({i, j});
            if(arr[i][j] == 2) chicken.push_back({i, j});
        }
    }

    vector<int> selected(chicken.size(), 0);
    fill(selected.end() - M, selected.end(), 1);

    do {
        int sum = 0;
        for(int i = 0; i < house.size(); i++) {
            int min_dis = INT_MAX;
            for(int j = 0; j < chicken.size(); j++) {
                if(selected[j] == 1) {
                    int dis = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);
                    min_dis = min(dis, min_dis);
                }
            }
            sum += min_dis;
        }

        result = min(result, sum);

    } while(next_permutation(selected.begin(), selected.end()));

    cout << result << endl;

    return 0;
}