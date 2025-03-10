#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<string> arr;

int main(void) {
    cin >> N >> M;

    arr.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int cnt = 0;
    vector<string> result;
    for(int j = 0; j < M; j++) {
        string s;
        cin >> s;
        if(binary_search(arr.begin(), arr.end(), s)) {
            cnt++;
            result.push_back(s);
        }
    }

    sort(result.begin(), result.end());
    cout << cnt << endl;
    for(string s: result) {
        cout << s << "\n";
    }

    return 0;
}