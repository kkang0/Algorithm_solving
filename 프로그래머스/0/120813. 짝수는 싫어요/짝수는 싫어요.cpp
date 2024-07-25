#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n) {
    vector<int> v;
    while(n > 0) {
        if(n % 2 != 0) v.push_back(n);
        n--;
    }
    
    sort(v.begin(), v.end());
    return v;
}