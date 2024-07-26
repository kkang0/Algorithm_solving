#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int solution(vector<string> s1, vector<string> s2) {
    unordered_set<string> set1(s1.begin(), s1.end());
    int count = 0;
    for(string s: s2) {
        if(set1.find(s) != set1.end()) count++;
    }
    
    return count;
}