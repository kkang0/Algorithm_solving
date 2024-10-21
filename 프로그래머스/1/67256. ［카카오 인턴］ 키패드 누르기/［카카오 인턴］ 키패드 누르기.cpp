#include <string>
#include <vector>
#include <cmath>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string result = "";

    int pos[2] = {10, 12};
    
    for(int i = 0; i < numbers.size(); i++) {
        int num = numbers[i];
        if(num == 1 || num == 4 || num == 7) {
            pos[0] = num;
            result += "L";
        } else if(num == 3 || num == 6 || num == 9) {
            pos[1] = num;
            result += "R";
        } else {
            if(num == 0) num = 11;
            
            int leftlen = abs(num - pos[0]) / 3 + abs(num - pos[0]) % 3;
            int rightlen = abs(num - pos[1]) / 3 + abs(num - pos[1]) % 3;
            
            if(leftlen < rightlen) {
                pos[0] = num;
                result += "L";
            } else if(leftlen > rightlen) {
                pos[1] = num;
                result += "R";
            } else {
                if(hand == "left") {
                    pos[0] = num;
                    result += "L";
                } else if(hand == "right") {
                    pos[1] = num;
                    result += "R";
                }
            }
        }
    }
    
    return result;
}