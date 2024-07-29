#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string before, string after) {
    if(before.size() != after.size()) {
        return 0;
    }
    
    sort(before.begin(), before.end());
    sort(after.begin(), after.end());

    return before == after ? 1 : 0;
}
