#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> numbers;
    long long fact = 1;
    
    for (int i = 1; i <= n; i++) {
        numbers.push_back(i);
        fact *= i;
    }
    
    k--;
    
    for (int i = 0; i < n; i++) {
        fact /= (n - i);
        int index = k / fact;
        answer.push_back(numbers[index]);
        numbers.erase(numbers.begin() + index);
        k %= fact;
    }
    
    return answer;
}