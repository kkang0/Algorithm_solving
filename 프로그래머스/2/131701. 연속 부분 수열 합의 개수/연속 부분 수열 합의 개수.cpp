#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> elements) {
    set<int> s;
    
    int cnt = 1;
    while(cnt != elements.size()) {
        for(int i = 0; i < elements.size(); i++) {
            int sum = 0;
            for(int j = i; j < i + cnt; j++) {
                if(j >= elements.size()) sum += elements[j - elements.size()];
                else sum += elements[j];
            }
            
            s.insert(sum);
        }
        
        cnt++;
    }
    
    return s.size() + 1;
}