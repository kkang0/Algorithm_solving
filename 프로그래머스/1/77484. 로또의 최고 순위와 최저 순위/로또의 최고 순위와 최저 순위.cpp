#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    int znum = 0;
    int wnum = 0;
    
    for(int i = 0; i < lottos.size(); i++) {
        if(lottos[i] == 0) {
            znum++;
        } else if(find(win_nums.begin(), win_nums.end(), lottos[i]) != win_nums.end()) {
            wnum++;
        }
    }
    
    vector<int> rankMap = {6, 6, 5, 4, 3, 2, 1};
    
    int highRank = 6;
    int lowRank = 6;
    for(int i = 0; i <= 6; i++) {
        if(wnum + znum == i) highRank = rankMap[i];
        if(wnum == i) lowRank = rankMap[i];
    }

    return {highRank, lowRank};
}