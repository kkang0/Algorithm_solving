#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, L;
    cin >> N >> L;
    vector<int> fruits;
    fruits.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> fruits[i];
    }

    sort(fruits.begin(), fruits.end());

    int len = L;
    for(int i = 0; i < N; i++) {
        if(fruits[i] <= len) len++;
    }

    cout << len << '\n';

    return 0;
}