#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string overwrite_string, int s) {
    int oversize = overwrite_string.size();
    my_string.erase(my_string.begin() + s, my_string.begin() + s + oversize);
    my_string.insert(s, overwrite_string);
    
    return my_string;
}