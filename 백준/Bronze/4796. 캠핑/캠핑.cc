#include <iostream>
using namespace std;

int main(void) {
    int case_num = 1;
    while(true) {
        int L, P, V;
        cin >> L >> P >> V;
        if(L == 0 && P == 0 && V == 0) break;

        int day = (V / P) * L;
        int remain = V % P;

        if(remain <= L) day += V % P;
        else day += L;

        cout << "Case " << case_num << ": " << day << endl;
        case_num++;
        day = 0;
        remain = 0;
    }

    return 0;
}