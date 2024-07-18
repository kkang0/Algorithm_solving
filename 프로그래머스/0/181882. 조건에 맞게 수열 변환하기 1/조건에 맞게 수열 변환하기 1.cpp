#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    for(int i = 0; i < arr.size(); i++) {
        int n = arr[i];
        if (n >= 50 && n % 2 == 0) arr[i] /= 2;
        else if (n < 50 && n % 2 != 0) arr[i] *= 2;
    }
    
    return arr;
}