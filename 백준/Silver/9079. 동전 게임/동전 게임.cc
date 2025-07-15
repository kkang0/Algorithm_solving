#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 1e9;
int coin[3][3];
bool visited[512];
int result;

void flipCol(int col) {
    for(int i = 0; i < 3; i++) {
        coin[i][col] = (coin[i][col] == 1 ? 0 : 1);
    }
}

void flipRow(int row) {
    for(int i = 0; i < 3; i++) {
        coin[row][i] = (coin[row][i] == 1 ? 0 : 1);
    }
}

void flipCross(int dir) {
    for(int i = 0; i < 3; i++) {
        if(dir == 0) {
            coin[i][i] = (coin[i][i] == 1 ? 0 : 1);
        }
        else {
            coin[i][2 - i] = (coin[i][2 - i] == 1 ? 0 : 1);
        }
    }
}

bool isSame() {
    char tmp = coin[0][0];
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(tmp != coin[i][j]) return false;
        }
    }
    return true;
}

int charToInt() {
    int cur = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cur = cur * 2 + coin[i][j];
        }
    }
    return cur;
}

void intToChar(int num) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            coin[i][j] = num % 2;
            num /= 2;
        }
    }
}

int bfs() {
    queue<pair<int, int>> q;
    int first = charToInt();
    q.push({first, 0});
    visited[first] = true;

    while(!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        intToChar(cur);

        if(isSame()) return cnt;

        for(int i = 0; i < 3; i++) {
            flipCol(i);
            int next = charToInt();
            if(!visited[next]) {
                visited[next] = true;
                q.push({next, cnt + 1});
            }
            flipCol(i);
        }

        for(int i = 0; i < 3; i++) {
            flipRow(i);
            int next = charToInt();
            if(!visited[next]) {
                visited[next] = true;
                q.push({next, cnt + 1});
            }
            flipRow(i);
        }

        for(int i = 0; i <= 1; i++) {
            flipCross(i);
            int next = charToInt();
            if(!visited[next]) {
                visited[next] = true;
                q.push({next, cnt + 1});
            }
            flipCross(i);
        }
    }
    
    return -1;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        result = MAX;
        memset(visited, false, sizeof(visited));
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                char c;
                cin >> c;
                if(c == 'H') coin[i][j]= 1;
                else coin[i][j] = 0;
            }
        }
        
        cout << bfs() << '\n';
    }

    return 0;
}