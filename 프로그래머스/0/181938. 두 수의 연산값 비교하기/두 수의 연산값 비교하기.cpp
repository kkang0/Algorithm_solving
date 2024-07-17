#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int n = stoi(to_string(a) + to_string(b));
    int m = 2 * a * b;
    
    if(n < m) return m;
    else return n;
}