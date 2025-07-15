#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<string> words;
bool visited[27];
int result;

bool readable(string word) {
    for(char c: word) {
        if(!visited[c - 'a']) return false;
    }
    return true;
}

void dfs(int idx, int cnt) {
    if(cnt == K - 5) {
        int readCnt = 0;
        for(string word: words) {
            if(readable(word)) readCnt++;
        }
        result = max(result, readCnt);
        return;
    }

    for(int i = idx; i < 26; i++) {
        if(!visited[i]) {
            visited[i] = true;
            dfs(i + 1, cnt + 1);
            visited[i] = false;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;


    visited['a' - 'a'] = true;
    visited['n' - 'a'] = true;
    visited['t' - 'a'] = true;
    visited['i' - 'a'] = true;
    visited['c' - 'a'] = true;

    for(int i = 0; i < N; i++) {
        string str;
        cin >> str;
        words.push_back(str);
    }

    if(K < 5) {
        cout << 0 << endl;
        return 0;
    }
    
    dfs(0, 0);

    cout << result << '\n';

    return 0;
}