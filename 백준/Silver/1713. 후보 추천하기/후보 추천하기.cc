#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> recs(K);
    for(int i = 0; i < K; i++) cin >> recs[i];

    struct Photo {
        int num;
        int rec;
        int time;
    };

    vector<Photo> frame;

    for(int t = 0; t < K; t++) {
        int cur = recs[t];
        int pos = -1;

        for(int i = 0; i < frame.size(); i++) {
            if(frame[i].num == cur) {
                pos = i;
                break;
            }
        }

        if(pos != -1) {
            frame[pos].rec++;
        } else {
            if(frame.size() < N) {
                frame.push_back({cur, 1, t});
            } else {
                int del = 0;
                for(int i = 1; i < frame.size(); i++) {
                    if(frame[i].rec < frame[del].rec ||
                      (frame[i].rec == frame[del].rec && frame[i].time < frame[del].time)) {
                        del = i;
                    }
                }

                frame.erase(frame.begin() + del);
                frame.push_back({cur, 1, t});
            }
        }
    }

    vector<int> ans;
    for(auto &p : frame) ans.push_back(p.num);

    sort(ans.begin(), ans.end());

    for(int x : ans) cout << x << " ";
    cout << "\n";

    return 0;
}