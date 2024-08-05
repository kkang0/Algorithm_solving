#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int save = 0;
    int person = people.size() - 1;
    
    int result = 0;
    sort(people.begin(), people.end());
    while(save <= person) {
        if(people[save] + people[person] <= limit) save++;
        person--;
        result++;
    }
    
    return result;
}