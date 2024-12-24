#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int left, right;
    int depth, order;
};

Node tree[10001];
int child[10001];
int min_cnt[10001];
int max_cnt[10001];
int o = 0;

void inorder(int n, int d) {
    if (n == -1) return;

    inorder(tree[n].left, d + 1);
    tree[n].depth = d;
    tree[n].order = ++o;
    inorder(tree[n].right, d + 1);
}

int main(void) {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int p, l, r;
        cin >> p >> l >> r;

        tree[p].left = l;
        tree[p].right = r;

        if (l != -1) child[l]++;
        if (r != -1) child[r]++;
    }

    int root = 1;
    for (int i = 1; i <= N; i++) {
        if (child[i] == 0) {
            root = i;
            break;
        }
    }

    fill(min_cnt, min_cnt + 10001, N + 1);
    fill(max_cnt, max_cnt + 10001, 0);

    inorder(root, 1);

    int max_depth = 0;
    for (int i = 1; i <= N; i++) {
        int depth = tree[i].depth;
        int order = tree[i].order;

        max_depth = max(max_depth, depth);
        min_cnt[depth] = min(min_cnt[depth], order);
        max_cnt[depth] = max(max_cnt[depth], order);
    }

    int width = 0, level = 0;
    for (int i = 1; i <= max_depth; i++) {
        int level_width = max_cnt[i] - min_cnt[i] + 1;
        if (level_width > width) {
            width = level_width;
            level = i;
        }
    }

    cout << level << " " << width << endl;

    return 0;
}