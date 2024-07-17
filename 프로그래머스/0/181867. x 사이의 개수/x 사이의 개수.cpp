#include <string>
#include <vector>

using namespace std;

vector<int> solution(string myString) {
    vector<int> v;
    int len = 0;
    for(int i = 0; i < myString.length(); i++) {
        if(myString[i] != 'x') {
            len++;
        } else {
            v.push_back(len);
            len = 0;
        }
    }
    
    v.push_back(len);
    
    return v;
}