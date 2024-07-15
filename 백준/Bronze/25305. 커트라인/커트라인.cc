#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
    return a > b;
}

int main(void) {
    int N, k, num;
    cin >> N >> k;

    vector<int> v;
    for(int i = 0; i < N; i++) {
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end(), compare);

    cout << v.at(k - 1) << '\n';

    return 0;
}