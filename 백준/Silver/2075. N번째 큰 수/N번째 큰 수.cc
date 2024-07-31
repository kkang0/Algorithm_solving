#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int num;
            cin >> num;
            if(minHeap.size() < N) minHeap.push(num);
            else if(num > minHeap.top()) {
                minHeap.pop();
                minHeap.push(num);
            }
        }
    }

    cout << minHeap.top() << endl;

    return 0;
}