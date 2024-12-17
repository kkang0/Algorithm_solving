#include <iostream>
#include <list>
#include <string>
using namespace std;

int main(void) {
    string s;
    cin >> s;

    int N;
    cin >> N;

    list<char> editor(s.begin(), s.end());
    auto cursor = editor.end();

    for (int i = 0; i < N; i++) {
        char command;
        cin >> command;

        if (command == 'L') {
            if (cursor != editor.begin()) {
                --cursor;
            }
        } else if (command == 'D') {
            if (cursor != editor.end()) {
                ++cursor;
            }
        } else if (command == 'P') {
            char to_insert;
            cin >> to_insert;
            editor.insert(cursor, to_insert);
        } else if (command == 'B') {
            if(cursor != editor.begin()) {
                cursor = editor.erase(prev(cursor));
            }
        }
    }

    for (char c : editor) {
        cout << c;
    }
    cout << endl;

    return 0;
}