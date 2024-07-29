#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    int x_limit = board[0] / 2;
    int y_limit = board[1] / 2;
    vector<int> result = {0, 0};

    for (const string& key : keyinput) {
        if (key == "left" && result[0] > -x_limit) result[0]--;
        if (key == "right" && result[0] < x_limit) result[0]++;
        if (key == "up" && result[1] < y_limit) result[1]++;
        if (key == "down" && result[1] > -y_limit) result[1]--;
    }

    return result;
}