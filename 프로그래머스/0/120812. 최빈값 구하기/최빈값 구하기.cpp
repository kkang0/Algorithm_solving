#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

int solution(vector<int> array) {
    map<int, int> frequency;
    for(int i: array) {
        frequency[i]++;
    }
    
    vector<pair<int, int>> freqVector(frequency.begin(), frequency.end());

    sort(freqVector.begin(), freqVector.end(), compare);
    
    if (freqVector.size() > 1 && freqVector[1].second == freqVector[0].second) {
        return -1;
    }
    
    return freqVector[0].first;
}
