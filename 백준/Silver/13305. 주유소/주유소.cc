#include <iostream>
using namespace std;

int dist[100000];
int cost[100000];

int main(void) {
    int N;
    cin >> N;

    for(int i = 1; i < N; i++) {
        cin >> dist[i];
    }

    for(int i = 0; i < N; i++) {
        cin >> cost[i];
    }
    
    long long cur_cost = cost[0];
    long long result = cur_cost * dist[1];

    for(int i = 1; i < N; i++) {
        if(cur_cost < cost[i]) result += cur_cost * dist[i + 1];
        else {
            cur_cost = cost[i];
            result += cur_cost * dist[i + 1];
        }
    }

    cout << result << endl;

    return 0;
}