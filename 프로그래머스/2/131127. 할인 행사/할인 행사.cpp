#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    unordered_map<string, int> target, current;
    for (int i = 0; i < want.size(); i++) {
        target[want[i]] = number[i];
    }
    
    int result = 0;
    for (int i = 0; i < 10 && i < discount.size(); i++) {
        current[discount[i]]++;
    }

    if (current == target) result++;

    for (int i = 10; i < discount.size(); i++) {
        current[discount[i]]++;
        current[discount[i - 10]]--;
        
        if (current[discount[i - 10]] == 0) {
            current.erase(discount[i - 10]);
        }

        if (current == target) result++;
    }
    
    return result;
}
