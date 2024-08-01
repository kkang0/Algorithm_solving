#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;

bool compare(string s1, string s2) {
    if(s1[N] != s2[N]) return s1[N] < s2[N];
    return s1 < s2;
}

vector<string> solution(vector<string> strings, int n) {
    N = n;
    sort(strings.begin(), strings.end(), compare);
    return strings;
}