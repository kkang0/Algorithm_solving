#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <set>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    map<string, set<string>> list;
    map<string, int> cnt;
    vector<int> result(id_list.size(), 0);
    
    for (const string& id : id_list) {
        cnt[id] = 0;
    }

    for (const string& r : report) {
        string n, m;
        stringstream s(r);
        s >> n >> m;
        
        if (list[n].insert(m).second) {
            cnt[m]++;
        }
    }
    
    for (int i = 0; i < id_list.size(); i++) {
        string user = id_list[i];
        
        for (const string& reported : list[user]) {
            if (cnt[reported] >= k) {
                result[i]++;
            }
        }
    }
    
    return result;
}