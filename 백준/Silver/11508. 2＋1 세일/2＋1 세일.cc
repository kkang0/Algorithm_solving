#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> dairy;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    dairy.resize(N);

    for(int i = 0; i < N; i++) cin >> dairy[i];

    sort(dairy.begin(), dairy.end(), greater<int>());

    int price = 0;
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(cnt == 2) {
            cnt = 0;
            continue;
        }
        price += dairy[i];
        cnt++;
    }

    cout << price << endl;

    return 0;
}