#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> result(2);
    for(int i = 0; i < num_list.size(); i++) {
        if(num_list[i] % 2 == 0) result[0]++;
        else result[1]++;
    }
    
    return result;
}