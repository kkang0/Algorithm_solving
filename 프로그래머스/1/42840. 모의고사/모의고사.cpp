#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> v3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int c1 = 0;
    int c2 = 0;
    int c3 = 0;
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == v1[i % 5]) c1++;
        if (answers[i] == v2[i % 8]) c2++;
        if (answers[i] == v3[i % 10]) c3++;
    }
    
    int max_score = max({c1, c2, c3});
    
    vector<int> answer;
    if (c1 == max_score) answer.push_back(1);
    if (c2 == max_score) answer.push_back(2);
    if (c3 == max_score) answer.push_back(3);
    
    return answer;
}
