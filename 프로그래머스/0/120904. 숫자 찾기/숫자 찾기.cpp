#include <string>
#include <vector>

using namespace std;

int solution(int num, int k) {
    string str = to_string(num);
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == (k + '0')) return (i + 1);
    }
    
    return -1;
}