#include <string>
#include <vector>

using namespace std;

string solution(string myString, string pat) {
    int index = myString.rfind(pat);
    return myString.substr(0, index + pat.size());
}