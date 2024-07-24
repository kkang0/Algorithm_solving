#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int idx;

bool compare(vector<int> a, vector<int> b) {
    if(a[idx] == b[idx]) return a > b;
    return a[idx] < b[idx];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    idx = col - 1;
    sort(data.begin(), data.end(), compare);
    
    vector<int> v;
    for(int i = row_begin - 1; i <= row_end - 1; i++) {
        int sum = 0;
        for(int j = 0; j < data[0].size(); j++) {
            sum += data[i][j] % (i + 1);
        }
        v.push_back(sum);
    }
    
    int result = 0;
    for(int i = 0; i < v.size(); i++) {
        result = result ^ v[i];
    }
    
    return result;
}