#include <string>
#include <vector>

using namespace std;

int binaryToDecimal(string b) {
    int num = 0;
    for(char c : b) {
        num = num * 2 + (c - '0');
    }
    return num;
}

string decimalToBinary(int num) {
    if(num == 0) return "0";
    string result = "";
    while(num > 0) {
        result = to_string(num % 2) + result;
        num /= 2;
    }
    return result;
}

string solution(string bin1, string bin2) {
    int b1 = binaryToDecimal(bin1);
    int b2 = binaryToDecimal(bin2);
    int sum = b1 + b2;
    string result = decimalToBinary(sum);
    
    return result;
}
