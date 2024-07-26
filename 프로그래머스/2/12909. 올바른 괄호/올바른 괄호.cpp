#include <string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    stack<char> st;
    for(char c : s) {
        if(c == '(') {
            st.push(c);
        } else if(c == ')') {
            if(st.empty() || st.top() != '(') {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}