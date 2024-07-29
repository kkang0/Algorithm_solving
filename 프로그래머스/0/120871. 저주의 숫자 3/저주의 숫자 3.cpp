#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    string str;
    for(int i = 1; i <= n; i++) {
        answer++;
        str = to_string(answer);
        while(answer % 3 == 0 || str.find('3') != string::npos) {
            answer++;
            str = to_string(answer);
        }
    }
    return answer;
}