#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

int N;
vector<int> v;

int main(void) {
    cin >> N;
    v.resize(N);

    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    
    int left = 0;
    int right = N - 1;
    int p1, p2;

    int min = INT_MAX;
    while(left < right) {
        int minNum = v[left] + v[right];
        if(min > abs(minNum)) {
            min = abs(minNum);
            p1 = v[left];
            p2 = v[right];
        }

        if(minNum < 0) left++;
        else right--;
    }

    cout << p1 << " " << p2 << endl;
    
    return 0;
}