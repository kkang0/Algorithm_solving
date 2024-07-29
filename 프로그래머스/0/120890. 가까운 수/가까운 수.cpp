#include <string>
#include <vector>
#include <cmath> // abs 함수 사용을 위해 추가

using namespace std;

int solution(vector<int> array, int n) {
    int dif = abs(array[0] - n);
    int result = array[0];
    for(int i: array) {
        int current_diff = abs(i - n);
        if(current_diff < dif) {
            dif = current_diff;
            result = i;
        }
        else if(current_diff == dif && i < result) {
            result = i;
        }
    }
    
    return result;
}
