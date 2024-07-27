#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(string my_string) {
    istringstream iss(my_string);
    int result;
    iss >> result;

    char op;
    int num;
    while (iss >> op >> num) {
        if (op == '+') {
            result += num;
        } else if (op == '-') {
            result -= num;
        }
    }
    return result;
}
