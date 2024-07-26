#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    string num = to_string(n);
    int sum = 0;
    for(char c: num) {
        sum += (c - '0');
    }
    return sum;
}