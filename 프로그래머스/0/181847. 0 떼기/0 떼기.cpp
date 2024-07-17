#include <string>
#include <vector>

using namespace std;

int find_idx(string str) {
    for(int i = 0; i < str.length(); i++) {
        if(str[i] != '0') return i;
    }
}

string solution(string n_str) {
    int idx = find_idx(n_str);
    
    return n_str.substr(idx);
}