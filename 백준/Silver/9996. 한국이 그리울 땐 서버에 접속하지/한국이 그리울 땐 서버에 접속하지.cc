#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    string pattern;
    cin >> pattern;
    
    int f = pattern.find('*');
    string pre = pattern.substr(0 , f);
    string post = pattern.substr(f + 1);
    vector<string> files(N);
    for(int i = 0; i < N; i++) cin >> files[i];

    for(string s: files) {
        if(s.size() < pre.size() + post.size()) {
            cout << "NE" << '\n';
            continue;
        }
        
        if(pre != s.substr(0, pre.size())) {
            cout << "NE" << '\n';
            continue;
        }
        if(post != s.substr(s.size() - post.size(), post.size())) {
            cout << "NE" << '\n';
            continue;
        }
        
        cout << "DA" << '\n';
    }

    return 0;
}