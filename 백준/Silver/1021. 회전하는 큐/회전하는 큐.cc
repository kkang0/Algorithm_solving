#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main(void) {
    int N, M;
    cin >> N >> M;

    vector<int> v;
    for(int i = 0; i < M; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    deque<int> dq;
    for(int i = 1; i <= N; i++) dq.push_back(i);

    int cnt = 0;
    for(int i = 0; i < v.size(); i++) {
        int target = v[i];
        int a, b = -1;

        while(target != dq.front()) {
            for (int i = 0; i < dq.size(); i++) {
                if (dq[i] == dq.front()) a = i;
                if (dq[i] == target) b = i;
            }

            int rd = (b - a + dq.size()) % dq.size();
            int ld = (a - b + dq.size()) % dq.size();

            if(rd < ld) {
                dq.push_back(dq.front());
                dq.pop_front();
                cnt++;
            } else {
                dq.push_front(dq.back());
                dq.pop_back();
                cnt++;
            }
        }

        dq.pop_front();
    }

    cout << cnt << endl;

    return 0;
}