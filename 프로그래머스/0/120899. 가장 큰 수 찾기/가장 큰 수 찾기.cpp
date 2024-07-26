#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array) {
    int max_num = array[0];
    int idx;
    for(int i = 0; i < array.size(); i++) {
        if(max_num < array[i]) {
            max_num = array[i];
            idx = i;
        }
    }
    
    return {max_num, idx};
}