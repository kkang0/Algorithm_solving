#include <iostream>
#include <algorithm>
using namespace std;

int order[1000];

int main(void) {
    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> order[i];
    }

    sort(order, order + N);

    int result = 0;
    for(int i = 0; i < N; i++) {
        result += order[i] * (N - i);
    }

    cout << result << endl;

    return 0;
}