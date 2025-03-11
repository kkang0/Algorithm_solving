#include <iostream>
#include <string>
using namespace std;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool test(string s) {
    bool flag = false;
    for (int i = 0; i < s.size(); i++) {
        if (isVowel(s[i])) flag = true;
\
        if (i >= 2 && 
           ((isVowel(s[i]) && isVowel(s[i - 1]) && isVowel(s[i - 2])) ||
            (!isVowel(s[i]) && !isVowel(s[i - 1]) && !isVowel(s[i - 2])))) {
            return false;
        }

        if (i >= 1 && s[i] == s[i - 1] && !(s[i] == 'e' || s[i] == 'o')) {
            return false;
        }
    }

    return flag;
}

int main(void) {
    while(true) {
        string s;
        cin >> s;

        if(s == "end") break;

        cout << "<" << s << "> "; 
        if(test(s)) cout << "is acceptable.\n";
        else cout << "is not acceptable.\n";
    }

    return 0;
}