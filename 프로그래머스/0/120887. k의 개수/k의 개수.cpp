#include <string>
#include <vector>

using namespace std;

int solution(int i, int j, int k) {
    int result = 0;
    string num = to_string(k);
    for(int m = i; m <= j; m++) {
        string s = to_string(m);
        for(char c: s) {
            if(c == num[0]) result++;
        }
    }
    
    return result;
}