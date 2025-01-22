#include <iostream>
using namespace std;

string video[65];

void quadtree(int size, int y, int x) {
    char cur = video[y][x];

    for(int i = y; i < y + size; i++) {
        for(int j = x; j < x + size; j++) {
            if(video[i][j] != cur) {
                cout << "(";
                quadtree(size / 2, y, x);
                quadtree(size / 2, y, x + size / 2);
                quadtree(size / 2, y + size / 2, x);
                quadtree(size / 2, y + size / 2, x + size / 2);
                cout << ")";
                return;
            }
        }
    }

    cout << cur;
}

int main(void) {
    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> video[i];
    }

    quadtree(N, 0, 0);
    cout << endl;

    return 0;
}