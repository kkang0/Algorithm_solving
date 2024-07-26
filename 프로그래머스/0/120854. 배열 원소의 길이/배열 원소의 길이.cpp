#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> strlist) {
    vector<int> len;
    for(int i = 0; i < strlist.size(); i++) {
        len.push_back(strlist[i].size());
    }
    return len;
}