#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int cnt = 0;
    
    for(string word: babbling) {
        int flag = 0;
        for(int i = 0; i < word.size();) {
            if(word.substr(i, 3) == "aya" && flag != 1) {
                flag = 1;
                i += 3;
            } else if(word.substr(i, 2) == "ye" && flag != 2) {
                flag = 2;
                i += 2;
            } else if(word.substr(i, 3) == "woo" && flag != 3) {
                flag = 3;
                i += 3;
            } else if(word.substr(i, 2) == "ma" && flag != 4) {
                flag = 4;
                i += 2;
            } else {
                flag = 0;
                break;
            }
        }
        
        if(flag) cnt++;
    }
    
    return cnt;
}