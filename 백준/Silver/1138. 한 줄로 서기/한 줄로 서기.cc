#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int N;
    cin >> N;

    vector<int> v(N, 0);
    for(int i = 1; i <= N; i++) {
        int x;
        cin >> x;

        for(int j = 0; j < N; j++) {
            if(x == 0 && v[j] == 0) {
                v[j] = i;
                break;
            }
            if(v[j] == 0) x--;
        }
    }

    for(int i = 0; i < N; i++) cout << v[i] << " ";
    cout << endl;

    return 0;
}