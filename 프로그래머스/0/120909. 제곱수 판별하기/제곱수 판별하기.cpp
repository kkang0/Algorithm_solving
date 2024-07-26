#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n) {
    int sqrt_n = sqrt(n);
    if (sqrt_n * sqrt_n == n) {
        return 1;
    } else {
        return 2;
    }
}
