#include <iostream>
#include <queue>
using namespace std;

bool visited[100001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, N});

    while(!pq.empty()) {
        int time = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        visited[cur] = true;

        if(cur == K) {
            cout << time << '\n';
            break;
        }

        if(cur - 1 >= 0 && !visited[cur - 1]) {
            pq.push({time + 1, cur - 1});
        }

        if(cur + 1 <= 100000 && !visited[cur + 1]) {
            pq.push({time + 1, cur + 1});
        }

        if(cur * 2 <= 100000 && !visited[cur * 2]) {
            pq.push({time, cur * 2});
        }
    }

    return 0;
}