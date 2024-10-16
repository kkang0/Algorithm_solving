#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

string solution(string X, string Y) {
    vector<int> xm(10, 0);
    
    for(int i = 0; i < X.size(); i++) {
        xm[X[i] - '0']++;
    }
    
    string result;
    for(int i = 0; i < Y.size(); i++) {
        if(xm[Y[i] - '0'] > 0) {
            xm[Y[i] - '0']--;
            result += Y[i];
        }
    }
    
    sort(result.begin(), result.end(), greater<char>());
    
    if(result.empty()) return "-1";
    if(result[0] == '0') return "0";
    
    return result;
}