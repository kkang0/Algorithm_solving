#include <string>
#include <vector>

using namespace std;

int solution(int chicken) {
    int total = 0;
    int coupon = 0;
    while(chicken > 0) {
        coupon += chicken;
        total += coupon / 10;
        chicken = coupon / 10;
        coupon %= 10;
    }
    
    return total;
}