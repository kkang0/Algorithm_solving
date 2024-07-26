#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int num1, int num2) {
    string str = my_string;
    str[num1] = my_string[num2];
    str[num2] = my_string[num1];
    return str;
}