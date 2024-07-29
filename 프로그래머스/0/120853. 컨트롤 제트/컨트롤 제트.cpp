#include <string>
#include <vector>
#include <sstream>
using namespace std;

int solution(string s) {
    stringstream ss(s);
    string str;
    vector<string> v;
    while (ss >> str) {
        v.push_back(str);
    }
    
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == "Z") {
            if (i > 0) {
                sum -= stoi(v[i - 1]);
            }
        } else {
            sum += stoi(v[i]);
        }
    }
    
    return sum;
}