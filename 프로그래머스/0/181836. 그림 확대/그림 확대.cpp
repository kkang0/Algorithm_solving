#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> picture, int k) {
    vector<string> result;
    for(int i = 0; i < picture.size(); i++) {
        string s;
        for(int j = 0; j < picture[i].size(); j++) {
            for(int m = 0; m < k; m++)
                s += picture[i][j];
        }
        for(int m = 0; m < k; m++) {
            result.push_back(s);
        }
    }
    
    return result;
}