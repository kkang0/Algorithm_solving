#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> numlist) {
    vector<int> v;
    for(int num: numlist) {
        if(num % n == 0) v.push_back(num);
    }
    
    return v;
}