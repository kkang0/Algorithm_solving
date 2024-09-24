#include <string>
#include <vector>
#include <string>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> result;
    
    for(int i = 0; i < targets.size(); i++) {
        int n = 0;
        bool check = true;
        
        for(int j = 0; j < targets[i].size(); j++) {
            char target = targets[i][j];
        
            int minIndex = 100;
            bool found = false;
            for(int k = 0; k < keymap.size(); k++) {
                int index = keymap[k].find(target);
                
                if(index != string::npos) {
                    minIndex = min(index, minIndex);
                    found = true;
                }
            }
            
            if(!found) {
                check = false;
                break;
            }
            
            n += minIndex + 1;
        }
        
        if(check) result.push_back(n);
        else result.push_back(-1);
    }
    
    return result;
}