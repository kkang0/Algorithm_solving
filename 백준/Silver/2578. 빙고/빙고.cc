#include <iostream>

using namespace std;

int arr[5][5];
pair<int, int> num[25];

bool check() {
    int bingo = 0;
    int crossR = 0, crossL = 0;

    for (int i = 0; i < 5; i++) {
        int row = 0, col = 0;
        for (int j = 0; j < 5; j++) {
            if (arr[i][j] == 0) row++;
            if (arr[j][i] == 0) col++;
        }
        if (row == 5) bingo++;
        if (col == 5) bingo++;
        if (arr[i][i] == 0) crossR++;
        if (arr[i][4 - i] == 0) crossL++;
    }
    if (crossR == 5) bingo++;
    if (crossL == 5) bingo++;

    return bingo >= 3;
}

int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> arr[i][j];
            num[arr[i][j] - 1] = {i, j};
        }
    }

    int ans = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int number;
            cin >> number;
            ans++;
            arr[num[number - 1].first][num[number - 1].second] = 0;

            if (check()) {
                cout << ans << endl;
                return 0;
            }
        }
    }

    return 0;
}