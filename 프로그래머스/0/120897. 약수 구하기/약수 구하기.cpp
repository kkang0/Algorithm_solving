#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> result;
    int i = 1;
    while(i <= n) {
        if(n % i == 0) result.push_back(i);
        i++;
    }
    
    return result;
}