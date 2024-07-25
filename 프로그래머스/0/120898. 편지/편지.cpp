#include <string>
#include <vector>

using namespace std;

int solution(string message) {
    int len = 0;
    for(int i = 0; i < message.size(); i++) {
        if(message[i] = ' ') len++;
    }
    
    return len * 2;
}