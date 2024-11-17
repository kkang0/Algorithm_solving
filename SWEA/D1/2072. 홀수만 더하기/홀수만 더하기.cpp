#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int T;
    cin >> T;

    vector<vector<int>> v(T, vector<int>(10));
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> v[i][j];
        }
    }

    vector<int> result(T, 0);
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < 10; j++) {
            if (v[i][j] % 2 != 0) {
                result[i] += v[i][j];
            }
        }
    }

    for (int i = 0; i < T; i++) {
        cout << "#" << i + 1 << " " << result[i] << endl;
    }

    return 0;
}