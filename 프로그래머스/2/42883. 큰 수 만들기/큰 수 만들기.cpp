#include <string>
#include <vector>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    int n = number.size();
    int target = n - k;
    
    for (char digit : number) {
        while (!answer.empty() && answer.back() < digit && k > 0) {
            answer.pop_back();
            k--;
        }
        answer.push_back(digit);
    }
    
    answer.resize(target);
    
    return answer;
}
