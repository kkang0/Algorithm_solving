#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int P;
    cin >> P;

    for (int T = 1; T <= P; T++) {
        int t;
        cin >> t;
        cout << t << " ";

        vector<int> order;
        int result = 0;

        for (int i = 0; i < 20; i++) {
            int h;
            cin >> h;

            int pos = order.size();
            for (int j = 0; j < order.size(); j++) {
                if (order[j] > h) {
                    pos = j;
                    break;
                }
            }

            order.insert(order.begin() + pos, h);

            result += order.size() - 1 - pos;
        }

        cout << result << "\n";
    }

    return 0;
}