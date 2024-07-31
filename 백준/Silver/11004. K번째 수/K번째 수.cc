#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K;
    cin >> N >> K;

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        pq.push(num);
    }

    for(int i = 0; i < K - 1; i++) pq.pop();
    cout << pq.top() << endl;

    return 0;
}