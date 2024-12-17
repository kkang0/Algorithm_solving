#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int cnt = 1;
    bool flag = true;
    stack<int> stk;
    vector<char> result;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        while (stk.empty() || stk.top() < num) { 
            stk.push(cnt);
            cnt++;
            result.push_back('+');
        }

        if (stk.top() == num) {
            stk.pop();
            result.push_back('-');
        } 
        else {
            flag = false;
            cout << "NO" << '\n';
            return 0;
        }
    }

    for (char c : result) {
        cout << c << '\n';
    }

    return 0;
}