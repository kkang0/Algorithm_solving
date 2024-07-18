#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> todo_list, vector<bool> finished) {
    vector<string> v;
    for(int i = 0; i < todo_list.size(); i++) {
        string s = todo_list[i];
        if(!finished[i]) v.push_back(s);
    }
    
    return v;
}