#include <iostream>
#include <unordered_map>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    unordered_map<string, int> um;
    for(int i = 0; i < N; i++) {
        string name;
        cin >> name;
        um[name]++;
    }

    for(int i = 0; i < N - 1; i++) {
        string name;
        cin >> name;
        um[name]--;
    }

    for(auto& a: um) {
        if(a.second != 0) cout << a.first << '\n';
    }

    return 0;
}