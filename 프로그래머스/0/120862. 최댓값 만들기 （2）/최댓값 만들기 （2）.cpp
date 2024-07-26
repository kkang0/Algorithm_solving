#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end());
    
    int len = numbers.size() - 1;
    int max1 = numbers[0] * numbers[1];
    int max2 = numbers[len] * numbers[len - 1];
    
    return max1 > max2 ? max1 : max2;
}