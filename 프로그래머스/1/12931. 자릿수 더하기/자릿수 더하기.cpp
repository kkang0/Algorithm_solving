#include <iostream>

using namespace std;
int solution(int n)
{
    int sum = 0;
    string num = to_string(n);
    for(char c: num) {
        sum += (c - '0');
    }
    return sum;
}