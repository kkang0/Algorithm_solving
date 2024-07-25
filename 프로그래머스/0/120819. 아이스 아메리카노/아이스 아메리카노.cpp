#include <string>
#include <vector>

using namespace std;

vector<int> solution(int money) {
    int count = money / 5500;
    int rest = money - count * 5500;
    return { count, rest };
}