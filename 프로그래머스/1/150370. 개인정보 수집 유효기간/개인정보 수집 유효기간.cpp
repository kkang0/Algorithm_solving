#include <string>
#include <vector>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> result;
    int year = stoi(today.substr(0, 4));
    int month = stoi(today.substr(5, 2));
    int day = stoi(today.substr(8, 2));
    
    vector<pair<char, int>> termMap;
    for(int i = 0; i < terms.size(); i++) {
        char type = terms[i][0];
        int n = stoi(terms[i].substr(2));
        termMap.push_back({type, n});
    }

    for(int i = 0; i < privacies.size(); i++) {
        int y = stoi(privacies[i].substr(0, 4));
        int m = stoi(privacies[i].substr(5, 2));
        int d = stoi(privacies[i].substr(8, 2));
        char t = privacies[i][11];
        

        int addMonth = 0;
        for(auto &term : termMap) {
            if(term.first == t) {
                addMonth = term.second;
                break;
            }
        }

        
        m += addMonth;
        y += (m - 1) / 12;
        m = (m - 1) % 12 + 1;  
        
        d--;
        if(d == 0) {
            d = 28;
            m--;
            if(m == 0) {
                m = 12;
                y--;
            }
        }

        if(year > y || (year == y && month > m) || (year == y && month == m && day > d)) {
            result.push_back(i + 1);
        }
    }
    
    return result;
}
