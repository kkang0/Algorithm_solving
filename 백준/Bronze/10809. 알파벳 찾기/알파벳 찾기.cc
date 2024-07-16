#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
    string s;
    cin >> s;

    vector<int> v;
    for(char c = 'a'; c <= 'z'; c++) {
        int index = s.find(c);
        
        if(index != string::npos) {
            v.push_back(index);
        } else {
            v.push_back(-1);
        }
    }

    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}