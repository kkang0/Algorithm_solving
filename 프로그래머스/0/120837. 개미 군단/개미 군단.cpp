#include <string>
#include <vector>

using namespace std;

int solution(int hp) {
    int count = 0;
    while(hp > 0) {
        if(hp >= 5) {
            count += hp / 5;
            hp = hp % 5;
        }else if(hp >= 3) {
            count += hp / 3;
            hp = hp % 3;
        } else {
            count += hp / 1;
            hp = hp % 1;
        }
    }
    return count;
}