#include <string>
#include <vector>

using namespace std;

int solution(vector<string> order) {
    int sum = 0;
    for(int i = 0; i < order.size(); i++) {
        if(order[i].find("latte") != string::npos) sum += 5000;
        else if(order[i].find("americano") != string::npos) sum += 4500;
        else if(order[i].find("anything") != string::npos) sum += 4500;
    }
    
    return sum;
}