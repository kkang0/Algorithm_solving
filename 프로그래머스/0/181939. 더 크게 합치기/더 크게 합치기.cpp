#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    string a1 = to_string(a);
    string b1 = to_string(b);
    
    if(a1 + b1 >= b1 + a1) return stoi(a1 + b1);
    else return stoi(b1 + a1);
}