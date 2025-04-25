#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, S, P;
vector<int> scores;

int compute_rank() {
    int rank = 1;
    for (int i = 0; i < scores.size(); i++) {
        if (S < scores[i]) {
            rank++;
        } else {
            break;
        }
    }
    return rank;
}

int main() {
    cin >> N >> S >> P;

    for (int i = 0; i < N; i++) {
        int score;
        cin >> score;
        scores.push_back(score);
    }

    scores.push_back(S);
    sort(scores.begin(), scores.end(), greater<int>());

    int rank = compute_rank();

    if (rank > P || (scores.size() > P && scores[P] == S)) {
        cout << -1 << "\n";
    } else {
        cout << rank << "\n";
    }

    return 0;
}