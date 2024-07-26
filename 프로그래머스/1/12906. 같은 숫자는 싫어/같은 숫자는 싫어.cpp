#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> v;
    int prev = arr[0];
    v.push_back(prev);
    for(int i = 0; i < arr.size(); i++) {
        int cur = arr[i];
        if(prev != cur) {
            v.push_back(cur);
            prev = cur;
        }
    }
    return v;
}