#include <string>
#include <vector>
using namespace std;

double solution(vector<int> numbers) {
    double sum = 0;
    int len = numbers.size();
    for(int i = 0; i < numbers.size(); i++) {
        sum += numbers[i];
    }
    return sum / len;
}