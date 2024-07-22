#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    vector<int> newArr = arr;
    int num = 0;
    bool changed = true;
    
    while(changed) {
        changed = false;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] % 2 == 0 && arr[i] >= 50) {
                newArr[i] = arr[i] / 2;
                changed = true;
            }
            else if(arr[i] % 2 != 0 && arr[i] < 50) {
                newArr[i] = arr[i] * 2 + 1;
                changed = true;
            }
            else {
                newArr[i] = arr[i];
            }
        }
        if (changed) {
            arr = newArr;
            num++;
        }
    }
    
    return num;
}
