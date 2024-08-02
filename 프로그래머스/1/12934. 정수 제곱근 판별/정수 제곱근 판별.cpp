#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(long long n) {
    long long sqrt_n = sqrt(n);

    return sqrt_n * sqrt_n == n ? (sqrt_n + 1) * (sqrt_n + 1) : -1;
}