#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<int> sensor;
vector<int> diff;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int pos;
        cin >> pos;
        sensor.push_back(pos);
    }

    sort(sensor.begin(), sensor.end());
    sensor.erase(unique(sensor.begin(), sensor.end()), sensor.end());

    int M = sensor.size();
    diff.resize(M - 1);
    for (int i = 0; i < M - 1; i++) {
        diff[i] = sensor[i + 1] - sensor[i];
    }

    sort(diff.begin(), diff.end(), greater<int>());

    int sum = 0;
    for (int i = K - 1; i < diff.size(); i++) {
        sum += diff[i];
    }

    cout << sum << '\n';
    return 0;
}