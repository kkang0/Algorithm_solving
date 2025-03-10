#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int main(void) {
    cin >> N >> M;

    vector<string> str(10001);
    for(int i = 0; i < N; i++) {
        cin >> str[i];
    }

    sort(str.begin(), str.end());

    int cnt = 0;
    for(int i = 0; i < M; i++) {
        string s;
        cin >> s;

        if(binary_search(str.begin(), str.end(), s)) cnt++;
    }

    cout << cnt << endl;

    return 0;
}