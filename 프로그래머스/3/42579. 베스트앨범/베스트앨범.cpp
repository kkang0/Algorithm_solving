#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    map<string, vector<pair<int, int>>> m;
    map<string, int> genrePlayCount;
    
    for(int i = 0; i < genres.size(); i++) {
        m[genres[i]].push_back({i, plays[i]});
        genrePlayCount[genres[i]] += plays[i];
    }
    
    vector<pair<string, int>> genreTotal(genrePlayCount.begin(), genrePlayCount.end());
    sort(genreTotal.begin(), genreTotal.end(), [](const auto &a, const auto &b) {
        return a.second > b.second;
    });
    
    vector<int> result;
    for(auto genre : genreTotal) {
        auto& songs = m[genre.first];
        
        sort(songs.begin(), songs.end(), [](const auto &a, const auto &b) {
            return a.second == b.second ? a.first < b.first : a.second > b.second;
        });
        
        int cnt = 0;
        for(auto song : songs) {
            if(cnt == 2) break;
            result.push_back(song.first);
            cnt++;
        }
    }
    
    return result;
}