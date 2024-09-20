#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    char str = '\0';
    int count = 0;
    int result = 0;
    
    for(char c: s) {
        if(str == '\0') {
            str = c;
            count++;
            continue;
        }
        
        if(str == c) count++;
        else {
            count--;
            
            if(count == 0) {
                result++;
                str = '\0';
            }
        }
    }
    
    if(count != 0) result++;
    
    return result;
}