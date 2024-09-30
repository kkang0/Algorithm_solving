#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> v;
    
    for(int i = 0; i < n; i++) {
        string row = "";
        int a1 = arr1[i];
        int a2 = arr2[i];
        
        for(int j = n - 1; j >= 0; j--) {
            int tmp1 = (a1 >> j) & 1;
            int tmp2 = (a2 >> j) & 1;
            int bit = tmp1 | tmp2;
            
            if(bit == 1) {
                row += "#";
            } else {
                row += " ";
            }
        }
        v.push_back(row);
    }
    
    return v;
}