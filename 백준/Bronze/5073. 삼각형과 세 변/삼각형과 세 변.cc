#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, b, c;

    while (true) {
        cin >> a >> b >> c;

        if (a == 0 && b == 0 && c == 0) break;

        int max_num = max({a, b, c});
        int sum = a + b + c;

        if (max_num >= sum - max_num) {
            cout << "Invalid" << endl;
            continue;
        }

        if (a == b && b == c) {
            cout << "Equilateral" << endl;
        }
        else if (a == b || a == c || b == c) {
            cout << "Isosceles" << endl;
        }
        else {
            cout << "Scalene" << endl;
        }
    }

    return 0;
}