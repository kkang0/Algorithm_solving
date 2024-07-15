#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int odd_sum = 0;
    int even_sum = 0;
    
    for(int i = 0; i < num_list.size(); i += 2) {
        odd_sum += num_list[i];
    }
    for(int i = 1; i < num_list.size(); i+= 2) {
        even_sum += num_list[i];
    }
    
    if(odd_sum > even_sum) return odd_sum;
    else if(odd_sum < even_sum) return even_sum;
    else return odd_sum;
}