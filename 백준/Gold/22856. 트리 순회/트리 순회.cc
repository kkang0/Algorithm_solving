#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[100001];
int child[100001];
int cnt = -1;
int r = -1;

void traverse(int n, bool flag) {
    if(n == -1) return;

    int left = tree[n][0];
    int right = tree[n][1];
    
    cnt++;
    traverse(left, 0);

    if(flag) {
        r++;
        traverse(right, 1);
    } else traverse(right, 0);
}

int main(void) {
    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        tree[a].push_back(b);
        tree[a].push_back(c);

        if(b != -1) child[b]++;
        if(c != -1) child[c]++;
    }

    traverse(1, 1);

    cout << cnt * 2 - r << endl;

    return 0;
}