#include <iostream>
using namespace std;

int N;
int triangle[1001];

bool check(int n) {
    for(int i = 1; i <= 50; i++)
        for(int j = 1; j <= 50; j++)
            for(int k = 1; k <= 50; k++) {
                if(triangle[i] + triangle[j] + triangle[k] == n) return true;
            }
    return false;
}

int main(void) {
    for(int i = 1; i <= 1000; i++) {
        triangle[i] = triangle[i - 1] + i;
    }

    cin >> N;
    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        cout << check(num) << '\n';
    }

    return 0;
}