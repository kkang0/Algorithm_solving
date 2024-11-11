#include <string>
#include <vector>
#include <map>
using namespace std;

long long solution(vector<int> weights) {
    map<int, int> m;
    for(int i = 0; i < weights.size(); i++) m[weights[i]]++;
    
    long long result = 0;
    for(auto a: m) {
        long long cnt = a.second;
        result += cnt * (cnt - 1) / 2;
    }
    
    for(auto a: m) {
        int weight = a.first;
        long long cnt = a.second;
        
        if (weight * 2 <= 1000 && m.find(weight * 2) != m.end()) {
            result += cnt * m[weight * 2];
        }
        
        if (weight % 2 == 0 && (weight / 2) * 3 <= 1000 && m.find((weight / 2) * 3) != m.end()) {
            result += cnt * m[(weight / 2) * 3];
        }
        
        if (weight % 3 == 0 && (weight / 3) * 4 <= 1000 && m.find((weight / 3) * 4) != m.end()) {
            result += cnt * m[(weight / 3) * 4];
        }
    }
    
    return result;
}