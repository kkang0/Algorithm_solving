#include <iostream>
#include <deque>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    deque<pair<int, int>> dq;
    for(int i = 1; i <= N; i++) {
        int n;
        cin >> n;
        dq.push_back({i, n});
    }

    while(N--) {
        auto [idx, k] = dq.front();
        dq.pop_front();

        cout << idx << " ";

        if(k > 0) {
            for(int i = 0; i < k - 1; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        } else {
            for(int i = 0; i < -k; i++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
    cout << endl;

    return 0;
}