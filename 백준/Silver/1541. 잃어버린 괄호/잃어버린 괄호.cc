#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

int getSum(string expr) {
    stringstream ss(expr);
    string token;
    int sum = 0;
    while(getline(ss, token, '+')) {
        sum += stoi(token);
    }

    return sum;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    vector<string> v;
    stringstream ss(s);
    string token;
    while(getline(ss, token, '-')) {
        v.push_back(token);
    }

    int result = getSum(v[0]);
    for(int i = 1; i < v.size(); i++) {
        result -= getSum(v[i]);
    }

    cout << result << "\n";

    return 0;
}