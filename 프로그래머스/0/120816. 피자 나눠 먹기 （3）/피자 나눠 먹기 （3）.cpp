#include <string>
#include <vector>
#include <math.h>
using namespace std;

int solution(int slice, int n) {
    int result = floor(n / slice);
    return n % slice == 0 ? result : result + 1;
}