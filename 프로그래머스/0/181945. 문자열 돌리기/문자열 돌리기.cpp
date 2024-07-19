#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string s;
    cin >> s;
    
    for(char c : s) {
        cout << c << endl;
    }
    
    return 0;
}