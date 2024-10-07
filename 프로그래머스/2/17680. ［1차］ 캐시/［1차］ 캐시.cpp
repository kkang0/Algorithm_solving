#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <cctype>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int time = 0;
    deque<string> dq;
    
    if(cacheSize == 0) return cities.size() * 5;
    
    for(int i = 0; i < cities.size(); i++) {
        string city;
        for(int j = 0; j < cities[i].size(); j++) {
            city += tolower(cities[i][j]);
        }
        
        auto it = find(dq.begin(), dq.end(), city);
        if(it != dq.end()) {    // cache hit
            dq.erase(it);
            dq.push_back(city);
            time++;
        } else if(it == dq.end()){ // cache miss
            if(dq.size() < cacheSize) {
                dq.push_back(city);
            } else {
                dq.pop_front();
                dq.push_back(city);
            }
            
            time += 5;
        }
    }
    
    return time;
}