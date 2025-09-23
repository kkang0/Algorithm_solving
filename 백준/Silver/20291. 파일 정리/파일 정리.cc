#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    map<string, int> m;
    for(int i = 0; i < N; i++) {
        string file;
        cin >> file;

        size_t idx = file.find('.');
        string ext = file.substr(idx + 1);
        m[ext]++;
    }

    for(auto& f: m) {
        cout << f.first << " " << f.second << "\n";
    }

    return 0;
}