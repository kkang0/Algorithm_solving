#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    vector<int> months = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<string> days = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    
    int day = 0;
    for(int i = 0; i < a - 1; i++) {
        day += months[i];
    }
    day += b;
    
    return days[(day - 1) % 7];
}