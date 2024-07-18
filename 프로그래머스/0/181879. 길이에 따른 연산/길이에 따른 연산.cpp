#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int sum = 0;
    int mul = 1;
    if(num_list.size() >= 11) {
        for(int i = 0; i < num_list.size(); i++) {
            sum += num_list[i];
        }
        
        return sum;
    } else {
        for(int i = 0; i < num_list.size(); i++) {
            mul *= num_list[i];
        }
        
        return mul;
    }
}