#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int> playerIndex;
    
    for(int i = 0; i < players.size(); i++) {
        playerIndex[players[i]] = i;
    }
    
    for(string s: callings) {
        int idx = playerIndex[s];
        
        swap(players[idx], players[idx - 1]);
        playerIndex[players[idx]] = idx;
        playerIndex[players[idx - 1]] = idx - 1;
    }
    
    return players;
}