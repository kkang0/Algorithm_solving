#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    int size = common.size() - 1;
    if(common[1] - common[0] == common[2] - common[1]) {
        return common[size] + common[1] - common[0];
    } else {
        return common[size] * (common[1] / common[0]);
    }
}