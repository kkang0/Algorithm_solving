#include <string>
#include <vector>

using namespace std;

vector<string> solution(string myStr) {
    string s;
    vector<string> v;
    for(int i = 0; i < myStr.size(); i++) {
        if(myStr[i] != 'a' && myStr[i] != 'b' && myStr[i] != 'c') s += myStr[i];
        else {
            if(s != "")
                v.push_back(s);
            s = "";
        }
    }
    
    if(s != "") v.push_back(s);
    if(v.size() == 0) return {"EMPTY"};
    return v;
}