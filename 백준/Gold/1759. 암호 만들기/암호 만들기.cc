#include <iostream>
#include <algorithm>
using namespace std;

int L, C;
char alphabet[16];

bool check(string s) {
    int vowels = 0;
    int consonants = 0;
    for (char c : s) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vowels++;
        } else {
            consonants++;
        }
    }
    return vowels >= 1 && consonants >= 2;
}

void dfs(int idx, string s) {
    if (s.length() == L) {
        if (check(s)) {
            cout << s << endl;
        }
        return;
    }

    for (int i = idx; i < C; i++) {
        dfs(i + 1, s + alphabet[i]);
    }
}

int main(void) {
    cin >> L >> C;

    for (int i = 0; i < C; i++) {
        cin >> alphabet[i];
    }

    sort(alphabet, alphabet + C);
    dfs(0, "");

    return 0;
}
