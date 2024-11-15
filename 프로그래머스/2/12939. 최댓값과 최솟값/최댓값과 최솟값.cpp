#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

string solution(string s) {
    stringstream ss(s);
    int num;
    vector<int> v;

    while (ss >> num) {
        v.push_back(num);
    }

    int minVal = *min_element(v.begin(), v.end());
    int maxVal = *max_element(v.begin(), v.end());
    
    return to_string(minVal) + " " + to_string(maxVal);
}