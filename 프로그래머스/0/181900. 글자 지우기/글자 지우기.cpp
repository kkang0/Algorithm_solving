#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string, vector<int> indices) {
    string str;
    for(int i = 0; i < my_string.size(); i++) {
        if(find(indices.begin(), indices.end(), i) == indices.end()) str += my_string[i];
    }
    
    return str;
}