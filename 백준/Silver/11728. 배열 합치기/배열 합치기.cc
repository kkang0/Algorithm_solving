#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int N, M;
    cin >> N >> M;

    vector<int> v;
    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    for(int i = 0; i < M; i++) {
        int b;
        cin >> b;
        v.push_back(b);
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}