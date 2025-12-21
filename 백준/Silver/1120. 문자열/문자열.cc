#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string A, B;
    cin >> A >> B;

    int result = A.size();

    for(int i = 0; i <= B.size() - A.size(); i++) {
        int diff = 0;
        for(int j = 0; j < A.size(); j++) {
            if(A[j] != B[i + j]) diff++;
        }
        result = min(result, diff);
    }

    cout << result << '\n';

    return 0;
}