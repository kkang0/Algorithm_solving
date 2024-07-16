#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<int> v(9);
    for(int i = 0; i < 9; i++) {
        cin >> v[i];
    }

    int max = *max_element(v.begin(), v.end());
    int max_index = max_element(v.begin(), v.end()) - v.begin();

    cout << max << endl;
    cout << max_index + 1 << endl;

    return 0;
}