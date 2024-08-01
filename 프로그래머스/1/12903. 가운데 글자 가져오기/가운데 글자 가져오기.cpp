#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int size = s.size();
    return size % 2 != 0 ? s.substr(size / 2, 1) : s.substr(size / 2 - 1, 2);
}