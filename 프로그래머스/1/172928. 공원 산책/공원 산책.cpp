#include <string>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> result;
    
    for(int i = 0; i < park.size(); i++) {
        int startIndex = park[i].find('S');
        
        if(startIndex != string::npos) {
            result.push_back(i);
            result.push_back(startIndex);
            break;
        }
    }
    
    int n = park.size();
    int m = park[0].size();
    for(int i = 0; i < routes.size(); i++) {
        char dir = routes[i][0];
        int cnt = routes[i][2] - '0';
        bool pos = true;
        
        if(dir == 'E') {
            if(result[1] + cnt > m - 1) continue;
            for(int j = 1; j <= cnt; j++) {
                if(park[result[0]][result[1] + j] == 'X') {
                    pos = false;
                    break;
                }
            }
            if(pos) result[1] += cnt;
        } else if(dir == 'W') {
            if(result[1] - cnt < 0) continue;
            for(int j = 1; j <= cnt; j++) {
                if(park[result[0]][result[1] - j] == 'X') {
                    pos = false;
                    break;
                }
            }
            if(pos) result[1] -= cnt;
        } else if(dir == 'S') {
            if(result[0] + cnt > n - 1) continue;
            for(int j = 1; j <= cnt; j++) {
                if(park[result[0] + j][result[1]] == 'X') {
                    pos = false;
                    break;
                }
            }
            if(pos) result[0] += cnt;
        } else if(dir == 'N') {
            if(result[0] - cnt < 0) continue;
            for(int j = 1; j <= cnt; j++) {
                if(park[result[0] - j][result[1]] == 'X') {
                    pos = false;
                    break;
                }
            }
            if(pos) result[0] -= cnt;
        }
    }
    
    return result;
}