#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int max_a = 0;
    int max_b = 0;
    for(int i = 0; i < sizes.size(); i++) {
        int a = sizes[i][0];
        int b = sizes[i][1];
        if(a > b) swap(a, b);
        if(max_a < a) max_a = a;
        if(max_b < b) max_b = b;
    }
    
    return max_a * max_b;
}