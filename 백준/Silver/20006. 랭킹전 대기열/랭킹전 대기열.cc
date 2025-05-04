#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool compare(pair<int, string> a, pair<int, string> b) {
    return a.second < b.second;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int p, m;
    cin >> p >> m;

    vector<vector<pair<int,string>>> rooms;
    for(int i = 0; i < p; i++) {
        int level;
        string id;
        cin >> level >> id;

        bool flag = false;
        for(int j = 0; j < rooms.size(); j++) {
            if(abs(rooms[j][0].first - level) <= 10 && rooms[j].size() < m) {
                rooms[j].push_back({level, id});
                flag = true;
                break;
            }
            
        }

        if(!flag) {
            rooms.push_back(vector<pair<int, string>>{{level, id}});
        }
    }

    for(int i = 0; i < rooms.size(); i++) {
        if(rooms[i].size() == m) {
            cout << "Started!" << "\n";
        } else if (rooms[i].size() < m) {
            cout << "Waiting!" << "\n";
        }

        sort(rooms[i].begin(), rooms[i].end(), compare);

        for(auto &a: rooms[i]) {
            cout << a.first << " " << a.second << "\n";
        }
    }

    return 0;
}