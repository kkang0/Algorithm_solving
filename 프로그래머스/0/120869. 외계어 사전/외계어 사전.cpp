#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<string> spell, vector<string> dic) {
    for (const string& word : dic) {
        unordered_set<char> letters(word.begin(), word.end());
        bool allFound = true;
        for (const string& letter : spell) {
            if (letters.find(letter[0]) == letters.end()) {
                allFound = false;
                break;
            }
        }
        if (allFound) return 1;
    }
    return 2;
}
