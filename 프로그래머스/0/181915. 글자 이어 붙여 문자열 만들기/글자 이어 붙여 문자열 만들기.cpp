#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<int> index_list) {
    string result;
    for(int i = 0; i < index_list.size(); i++) {
        int idx = index_list[i];
        result += my_string[idx];
    }
    
    return result;
}