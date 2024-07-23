#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> rank, vector<bool> attendance) {
    vector<pair<int, int>> v;
    for(int i = 0; i < attendance.size(); i++) {
        if(attendance[i]) v.push_back({rank[i], i});
    }
    
    sort(v.begin(), v.end());
    int a = v[0].second;
    int b = v[1].second;
    int c = v[2].second;
    
    return 10000 * a + 100 * b + c;
}