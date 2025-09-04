#include <iostream>
#include <map>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;

        map<string, int> m;
        for(int i = 0; i < n; i++) {
            string name, type;
            cin >> name >> type;
            m[type]++;
        }

        int result = 1;
        for(auto& type: m) {
            result *= (type.second + 1);
        }

        cout << result - 1 << '\n';
    }

    return 0;
}