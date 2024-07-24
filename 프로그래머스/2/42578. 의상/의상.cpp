#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> map;
    for(int i = 0; i < clothes.size(); i++) {
        map[clothes[i][1]]++;
    }
    
    int result = 1;
    for(auto c: map) {
        result *= (c.second += 1);
    }
    
    return result - 1;
}