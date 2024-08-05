#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void make_words(vector<string>& words, string cur, int max_len) {
    if(cur.size() > max_len) return;
    if(!cur.empty()) words.push_back(cur);
    
    vector<char> alphabet = {'A', 'E', 'I', 'O', 'U'};
    for(char alpha: alphabet) {
        make_words(words, cur + alpha, max_len);
    }
}

int solution(string word) {
    vector<string> words;
    string cur = "";
    int max_len = 5;
    make_words(words, cur, max_len);
    
    sort(words.begin(), words.end());
    auto it = find(words.begin(), words.end(), word);
    return distance(words.begin(), it + 1);
}