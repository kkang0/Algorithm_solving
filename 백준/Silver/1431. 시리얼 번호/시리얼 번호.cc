#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sum(string s) {
    int sum = 0;
    for(int i = 0; i < s.length(); i++) {
        if(isdigit(s[i])) sum += s[i] - '0';
    }

    return sum;
} 

bool compare(string a, string b) {
    if (a.length() != b.length()) return a.length() < b.length();
    else {
        if(sum(a) != sum(b)) return sum(a) < sum(b);
        else return a < b;
    }
}

int main(void) {
    int N;
    cin >> N;

    vector<string> v(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), compare);

    for(int i = 0; i < N; i++) {
        cout << v[i] << '\n';
    }

    return 0;
}