#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int result = 0;
    for(int i = 0; i < array.size(); i++) {
        string num = to_string(array[i]);
        for(char c: num) {
            if(c == '7') result++;
        }
    }
    
    return result;
}