#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int height) {
    int sum = 0;
    for(int i = 0; i < array.size(); i++) {
        if(array[i] > height) sum++;
    }
    return sum;
}