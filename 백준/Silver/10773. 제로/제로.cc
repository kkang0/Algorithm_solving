#include <iostream>
#include <stack>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    cin >> K;

    int sum = 0;
    stack<int> s;
    for(int i = 0; i < K; i++) {
        int num;
        cin >> num;

        if(num == 0) {
            sum -= s.top();
            s.pop();
        }
        else {
            s.push(num);
            sum += num;
        }
    }

    cout << sum << '\n';

    return 0;
}