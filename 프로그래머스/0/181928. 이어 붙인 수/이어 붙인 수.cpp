#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> num_list) {
    string odd;
    string even;
    for(int i = 0; i < num_list.size(); i++) {
        int num = num_list[i];
        if(num % 2 == 0) {
            even += to_string(num);
        } else {
            odd += to_string(num);
        }
    }
    
    return stoi(even) + stoi(odd);
}