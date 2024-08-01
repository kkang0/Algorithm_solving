#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int psum = 0;
    int ysum = 0;
    for(char c: s) {
        c = tolower(c);
        if(c == 'p') psum++;
        if(c == 'y') ysum++;
    }
    
    return psum == ysum ? true : false;
}