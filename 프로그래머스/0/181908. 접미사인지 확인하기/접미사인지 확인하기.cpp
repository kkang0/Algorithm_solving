#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_suffix) {
    int slen = is_suffix.length();
    int mlen = my_string.length();
    
    if(slen <= mlen) {
        string s = my_string.substr(mlen - slen);
        return s == is_suffix ? 1 : 0;
    } else return 0;
}