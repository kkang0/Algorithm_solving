#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int count_move(string s, char color, bool to_left) {
    int n = s.size();
    int count = 0;

    if (to_left) {
        // 왼쪽에서 연속된 color 제외
        int i = 0;
        while (i < n && s[i] == color) i++;
        for (; i < n; i++) {
            if (s[i] == color) count++;
        }
    } else {
        // 오른쪽에서 연속된 color 제외
        int i = n - 1;
        while (i >= 0 && s[i] == color) i--;
        for (int j = 0; j <= i; j++) {
            if (s[j] == color) count++;
        }
    }

    return count;
}

int main() {
    int N;
    string balls;
    cin >> N >> balls;

    int red_left = count_move(balls, 'R', true);
    int red_right = count_move(balls, 'R', false);
    int blue_left = count_move(balls, 'B', true);
    int blue_right = count_move(balls, 'B', false);

    int result = min({red_left, red_right, blue_left, blue_right});
    cout << result << '\n';
    return 0;
}