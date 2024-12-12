#include <iostream>
#include <queue>
using namespace std;

#define MAX 100001

int N, K;
int visited[MAX];

int bfs() {
    queue<int> q;
    q.push(N);
    visited[N] = 0;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        if(cur == K) break;

        if(cur - 1 >= 0 && visited[cur - 1] == 0) {
            q.push(cur - 1);
            visited[cur - 1] = visited[cur] + 1;
        }
        if(cur + 1 < MAX && visited[cur + 1] == 0) {
            q.push(cur + 1);
            visited[cur + 1] = visited[cur] + 1;
        }
        if(cur * 2 < MAX && visited[cur * 2] == 0) {
            q.push(cur * 2);
            visited[cur * 2] = visited[cur] + 1;
        }
    }

    return visited[K];
}

int main(void) {
    cin >> N >> K;

    cout << bfs() << endl;

    return 0;
}