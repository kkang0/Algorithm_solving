#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int m, int c) {
    string v;
    for(int i = 0; i < my_string.size(); i++) {
        if(i % m + 1 == c) v += my_string[i];
    }
    
    return v;
}