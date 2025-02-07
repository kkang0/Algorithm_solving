#include <iostream>
#include <queue>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int H, N, Q;
    cin >> H;
    cin >> N >> Q;
 
    priority_queue <int, vector <int>, greater<int>> pq;
    long long sum = 0;
    for(int i = 0; i < N; i++) {
        int d;
        cin >> d;
        pq.push(d);
        sum += d;
    }

    priority_queue<int, vector<int>, greater<int>> tmp = pq;
    long long tmp_sum = sum;
    while(!tmp.empty() && tmp_sum - tmp.top() >= H) {
        tmp_sum -= tmp.top();
        tmp.pop();
    }

    if(tmp_sum < H) cout << -1 << endl;
    else cout << tmp.size() << endl;

    for(int i = 0; i < Q; i++) {
        int x;
        cin >> x;
        pq.push(x);
        sum += x;

        while(!pq.empty() && sum - pq.top() >= H) {
            sum -= pq.top();
            pq.pop();
        }

        if(sum < H) cout << -1 << '\n';
        else cout << pq.size() << '\n';
    }

    return 0;
}