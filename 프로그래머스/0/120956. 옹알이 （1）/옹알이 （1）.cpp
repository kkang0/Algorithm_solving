#include <string>
#include <vector>
#include <regex>
using namespace std;

int solution(vector<string> babbling) {
    int sum = 0;
    
    regex pattern("(aya|ye|woo|ma)+");
    
    for(string word : babbling) {
        if(regex_match(word, pattern)) {
            sum++;
        }
    }
    
    return sum;
}
