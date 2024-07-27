#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int sum = 0;
    string s;
    for (char c : my_string) {
        if (isdigit(c)) {
            s += c;
        } else {
            if (!s.empty()) {
                sum += stoi(s);
                s.clear();
            }
        }
    }
    if (!s.empty()) {
        sum += stoi(s);
    }
    return sum;
}
