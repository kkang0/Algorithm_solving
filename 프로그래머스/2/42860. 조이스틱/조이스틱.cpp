#include <algorithm>
#include <string>

using namespace std;

int solution(string name) {
    int answer = 0;
    int n = name.length();
    int min_move = n - 1;

    for (int i = 0; i < n; i++) {
        if (name[i] - 'A' < 14) answer += name[i] - 'A';
        else answer += 'Z' - name[i] + 1;

        int next = i + 1;
        while (next < n && name[next] == 'A') 
            next++;

        min_move = min(min_move, i + n - next + min(i, n - next));
    }

    answer += min_move;
    return answer;
}
