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

    int result[1000];
    int sum = 0;
    for(int i = 0; i < N; i++) {
        sum += order[i];
        result[i] = sum;
    }

    int answer = 0;
    for(int i = 0; i < N; i++) {
        answer += result[i];
    }

    cout << answer << endl;

    return 0;
}