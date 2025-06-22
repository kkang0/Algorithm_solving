#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, C;
vector<char> alpha;
vector<char> tmp;

bool check(vector<char> t) {
    int vo = 0;
    int co = 0;
    for(char c: t) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') vo++;
        else co++;
    }

    return vo >= 1 && co >= 2;
}

void password(int idx) {
    if(tmp.size() == L) {
        if(check(tmp)) {
            for(int i = 0; i < tmp.size(); i++) cout << tmp[i];
            cout << '\n';
        }
        return;
    }

    for(int i = idx; i < C; i++) {
        tmp.push_back(alpha[i]);
        password(i + 1);
        tmp.pop_back();
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> L >> C;
    alpha.resize(C);
    for(int i = 0; i < C; i++) {
        cin >> alpha[i];
    }

    sort(alpha.begin(), alpha.end());

    password(0);

    return 0;
}