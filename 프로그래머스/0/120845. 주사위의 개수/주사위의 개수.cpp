#include <string>
#include <vector>

using namespace std;

int solution(vector<int> box, int n) {
    int x = box[0];
    int y = box[1];
    int z = box[2];
    return (x / n) * (y / n) * (z / n);
}