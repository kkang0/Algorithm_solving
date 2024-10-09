#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool compare(pair<int, double> a, pair<int, double> b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    unordered_map<int, int> um;
    vector<pair<int, double>> result;
    
    for(int i = 0; i < stages.size(); i++) {
        if(stages[i] <= N)
            um[stages[i]]++;
    }
    
    double people = stages.size();
    for(int i = 1; i <= N; i++) {
        if(people > 0) {
            double fail = um[i] / people;
            people -= um[i];
            result.push_back({i, fail});   
        } else {
            result.push_back({i, 0.0});
        }
    }
    
    sort(result.begin(), result.end(), compare);
    vector<int> answer;
    for(auto a: result) {
        answer.push_back(a.first);
    }
    
    return answer;
}