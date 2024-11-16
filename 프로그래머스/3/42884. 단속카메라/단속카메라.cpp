#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(vector<int> &a, vector<int> &b) {
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int result = 1;
    sort(routes.begin(), routes.end(), compare);
    
    int max = routes[0][1];
    for(auto r: routes) {
        if(max < r[0]) {
            max = r[1];
            result++;
        }
    }
    
    return result;
}