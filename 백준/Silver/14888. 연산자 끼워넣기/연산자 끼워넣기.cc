#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int N;
vector<int> v(N);
vector<int> op(4);

int max_num = INT_MIN;
int min_num = INT_MAX;

void dfs(int cur, int total) {
    if(cur == N) {
        max_num = max(max_num, total);
        min_num = min(min_num, total);
        return;
    }

    for(int i = 0; i < 4; i++) {
        if(op[i] == 0) continue;
        op[i]--;

        switch(i) {
            case 0: dfs(cur + 1, total + v[cur]);
                break;
            case 1: dfs(cur + 1, total - v[cur]);
                break;
            case 2: dfs(cur + 1, total * v[cur]);
                break;
            case 3: dfs(cur + 1, total / v[cur]);
                break;
        }
        op[i]++;
    }
}

int main(void) {
    cin >> N;

    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    for(int i = 0; i < 4; i++) {
        cin >> op[i];
    }

    dfs(1, v[0]);

    cout << max_num << endl;
    cout << min_num << endl;

    return 0;
}