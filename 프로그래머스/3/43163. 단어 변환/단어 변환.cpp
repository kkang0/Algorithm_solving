#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int result = 50;
bool visited[50];

bool compare(string a, string b) {
    int cnt = 0;
    
    for(int i = 0; i < a.size(); i++) {
        if(a[i] != b[i]) cnt++;
    }
    
    if(cnt == 1) return true;
    return false;
}

void dfs(string cur, string target, vector<string> words, int cnt) {
    if(cur == target) {
        result = min(result, cnt);
        return;
    }
    
    for(int i = 0; i < words.size(); i++) {
        if(!visited[i] && compare(cur, words[i])) {
            visited[i] = true;
            dfs(words[i], target, words, cnt + 1);
            visited[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    if(find(words.begin(), words.end(), target) == words.end()) return 0;
    
    dfs(begin, target, words, 0);
    
    return result;
}