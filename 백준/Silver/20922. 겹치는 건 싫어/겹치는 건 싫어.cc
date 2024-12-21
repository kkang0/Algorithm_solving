#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main(void) {
    int N, K;
    cin >> N >> K;

    vector<int> v(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }

    unordered_map<int, int> m;
    int left = 0;
    int result = 0;
    for(int right = 0; right < N; right++) {
        m[v[right]]++;

        while(!m.empty() && m[v[right]] > K) {
            m[v[left]]--;

            if(m[v[left]] == 0) {
                m.erase(v[left]);
            }
            left++;
        }

        result = max(result, right - left + 1);
    }

    cout << result << endl;

    return 0;
}