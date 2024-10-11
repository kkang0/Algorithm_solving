#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s, string skip, int index) {
    for(int i = 0; i < s.size(); i++) {
        char c = s[i];
        int count = 0;
        
        while(count < index) {
            c++;
            if(c > 'z') c = 'a';
            
            if(find(skip.begin(), skip.end(), c) == skip.end()) {
                count++;
            }
        }
        
        s[i] = c;
    }
    
    return s;
}