#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int num;

bool compare(int a, int b) {
    int gap1 = abs(num - a);
    int gap2 = abs(num - b);
    
    if(gap1 == gap2) return a > b;
    
    return gap1 < gap2;
}

vector<int> solution(vector<int> numlist, int n) {
    num = n;
    sort(numlist.begin(), numlist.end(), compare);
    
    return numlist;
}