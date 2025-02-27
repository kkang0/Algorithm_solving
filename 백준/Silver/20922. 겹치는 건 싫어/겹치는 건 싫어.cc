#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int A[200001];

int main(void) {
    int N, K;
    cin >> N >> K;

    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    unordered_map<int, int> m;
    int left = 0;
    int result = 0;
    for(int right = 0; right < N; right++) {
        m[A[right]]++;

        while(!m.empty() && m[A[right]] > K) {
            m[A[left]]--;

            if(m[A[left]] == 0) m.erase(A[left]);
            left++;
        }

        result = max(result, right - left + 1);
    }

    cout << result << endl;

    return 0;
}