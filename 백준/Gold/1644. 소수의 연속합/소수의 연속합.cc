#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N;
vector<int> v;
vector<bool> prime;

int main(void) {
    cin >> N;

    prime.resize(N + 1, false);
    for(int i = 2; i <= N; i++) {
        if(prime[i]) continue;
        else {
            v.push_back(i);
            for(int j = i * 2; j <= N; j += i) prime[j] = true;
        }
    }

    int start = 0, end = 0, sum = 0, result = 0;
    while(true) {
        if(sum >= N) sum -= v[start++];
        else if(end == v.size()) break;
        else sum += v[end++];

        if(sum == N) result++;
    }

    cout << result << endl;

    return 0;
}