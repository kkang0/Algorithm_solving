#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;

    vector<int> A(N), B(M);
    
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    for(int i = 0; i < M; i++) {
        cin >> B[i];
    }

    int i = 0, j = 0;
    vector<int> result;
    
    while (i < N && j < M) {
        if (A[i] < B[j]) {
            result.push_back(A[i]);
            i++;
        } else {
            result.push_back(B[j]);
            j++;
        }
    }

    while (i < N) {
        result.push_back(A[i]);
        i++;
    }

    while (j < M) {
        result.push_back(B[j]);
        j++;
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}