#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<unsigned long long> subject(N);

    for (int i = 0; i < N; ++i) {
        int t;
        cin >> t;
        unsigned long long mask = 0;
        for (int j = 0; j < t; ++j) {
            int x;
            cin >> x;
            mask |= (1ULL << (x - 1));
        }
        subject[i] = mask;
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int t;
        cin >> t;
        unsigned long long student_mask = 0;
        for (int j = 0; j < t; ++j) {
            int x;
            cin >> x;
            student_mask |= (1ULL << (x - 1));
        }

        int count = 0;
        for (int j = 0; j < N; ++j) {
            if ((student_mask & subject[j]) == subject[j]) {
                count++;
            }
        }

        cout << count << '\n';
    }

    return 0;
}