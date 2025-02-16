#include <iostream>
#include <unordered_map>
using namespace std;

int N, M;
unordered_map<int, int> m;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    for(int i = 0; i < N; i++) {
        int n;
        cin >> n;
        m[n]++;
    }

    cin >> M;
    for(int i = 0; i < M; i++) {
        int n;
        cin >> n;
        
        cout << m[n] << " ";
    }

    cout << endl;

    return 0;
}