#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int A[4001], B[4001], C[4001], D[4001];

int main(void) {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    vector<long long> first, second;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            first.push_back(A[i] + B[j]);
            second.push_back(C[i] + D[j]);
        }
    }

    sort(first.begin(), first.end());
    sort(second.begin(), second.end());

    long long result = 0;

    for(int i = 0; i < first.size(); i++) {
        int acnt = lower_bound(second.begin(), second.end(), -first[i]) - second.begin();
        int bcnt = upper_bound(second.begin(), second.end(), -first[i]) - second.begin();

        result += (bcnt - acnt);
    }

    cout << result << endl;
    
    return 0;
}