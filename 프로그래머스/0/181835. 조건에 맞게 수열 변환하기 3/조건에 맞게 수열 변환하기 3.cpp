#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    int ans;
    if(k % 2 != 0) {
        ans = 1;
    } else {
        ans = 0;
    }
    
    for(int i = 0; i < arr.size(); i++) {
        if(ans == 1) arr[i] *= k;
        else if (ans == 0) arr[i] += k;
    }
    
    return arr;
}