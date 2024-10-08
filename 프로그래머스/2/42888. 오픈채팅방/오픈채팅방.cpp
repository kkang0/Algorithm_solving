#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<pair<string, string>> p;
    unordered_map<string, string> m;
    
    for(int i = 0; i < record.size(); i++) {
        stringstream ss(record[i]);
        string enter, id, name;
        ss >> enter >> id >> name;
        
        p.push_back({enter, id});
        if(enter != "Leave") m[id] = name;
    }
    
    vector<string> result;
    for(int i = 0; i < record.size(); i++) {
        string str;
        str += m[p[i].second];
        if(p[i].first == "Enter") str += "님이 들어왔습니다.";
        else if(p[i].first == "Leave") str += "님이 나갔습니다.";
        else if(p[i].first == "Change") continue;
        result.push_back(str);
    }
    
    return result;
}