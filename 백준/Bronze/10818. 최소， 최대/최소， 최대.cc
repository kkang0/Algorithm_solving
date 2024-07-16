#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int N;
    cin >> N;

    int arr[1000000];
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int min = *min_element(arr, arr + N);
    int max = *max_element(arr, arr + N);

    cout << min << " " << max << endl;


    return 0;
}