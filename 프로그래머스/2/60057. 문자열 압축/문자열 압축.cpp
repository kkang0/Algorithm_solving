#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int slen = s.size();
    int minsize = slen;

    for (int unit = 1; unit <= slen / 2; unit++) {
        string comp;
        int count = 1;
        string prev = s.substr(0, unit);
        for (int i = unit; i < slen; i += unit) {
            string cur = s.substr(i, unit);
            if (prev == cur) {
                count++;
            } else {
                if (count > 1) {
                    comp += to_string(count);
                }
                comp += prev;
                prev = cur;
                count = 1;
            }
        }

        if (count > 1) {
            comp += to_string(count);
        }
        comp += prev;

        minsize = min(static_cast<int>(comp.size()), minsize);
    }

    return minsize;
}
