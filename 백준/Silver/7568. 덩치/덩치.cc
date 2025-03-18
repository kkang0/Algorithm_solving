#include <iostream>
using namespace std;

int main(void) {
    int N;
    cin >> N;

    pair<int, int> p[51];
    for(int i = 0; i < N; i++) {
        cin >> p[i].first >> p[i].second;
    }

    int rank = 1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(p[i].first < p[j].first && p[i].second < p[j].second) rank++;
        }
        cout << rank << " ";
        rank = 1;
    }
    cout << endl;
    
    return 0;
}