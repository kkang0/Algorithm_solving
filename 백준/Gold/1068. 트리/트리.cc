#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[51];
int child[51];
bool visited[51];
int node = -1;
int leaf = 0;
int root = -1;

void dfs(int n) {
    if(n == node) return;
    visited[n] = true;

    bool isLeaf = true;

    for(int i = 0; i < tree[n].size(); i++) {
        int c = tree[n][i];

        if(!visited[c] && c != node) {
            isLeaf = false;
            dfs(c);
        }
    }

    if(isLeaf) leaf++;
}

int main(void) {
    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        int parent;
        cin >> parent;

        if(parent != -1)
            tree[parent].push_back(i);
        else root = i;
    }

    int e;
    cin >> e;
    node = e;

    if(node != root)
        dfs(root);

    cout << leaf << endl;

    return 0;
}