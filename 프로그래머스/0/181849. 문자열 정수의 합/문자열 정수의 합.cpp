#include <string>
#include <vector>

using namespace std;

int solution(string num_str) {
    int sum = 0;
    for(int i = 0; i < num_str.length(); i++) {
        char c = num_str[i];
        sum += c - '0';
    }
    
    return sum;
}