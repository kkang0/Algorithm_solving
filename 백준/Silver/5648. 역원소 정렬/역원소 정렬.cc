#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n;
    cin >> n;

    string v[n];
    vector<long long> result;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        reverse(v[i].begin(), v[i].end());
        result.push_back(atoll(v[i].c_str()));
    }

    sort(result.begin(), result.end());

    for(long long a: result) cout << a << "\n";

    return 0;
}