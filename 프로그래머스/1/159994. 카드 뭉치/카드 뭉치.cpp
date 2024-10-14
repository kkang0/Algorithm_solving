#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int card1 = 0;
    int card2 = 0;
    for(int i = 0; i < goal.size(); i++) {
        string word = goal[i];
        
        if(card1 < cards1.size() && cards1[card1] == word) {
            card1++;
        } else if(card2 < cards2.size() && cards2[card2] == word) {
            card2++;
        } else return "No";
    }
    
    return "Yes";
}