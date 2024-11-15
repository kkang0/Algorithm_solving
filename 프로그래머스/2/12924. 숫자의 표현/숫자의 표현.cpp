#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int cnt = 0;

    for (int k = 1; k * (k - 1) / 2 < n; ++k) {
        int num = n - k * (k - 1) / 2;
        if (num % k == 0) {
            int a = num / k;
            if (a > 0) cnt++;
        }
    }

    return cnt;
}