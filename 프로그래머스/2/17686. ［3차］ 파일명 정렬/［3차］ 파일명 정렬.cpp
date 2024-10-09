#include <string>
#include <vector>
#include <iostream>
#include <cctype>
#include <algorithm>
using namespace std;

bool compare(vector<string> v1, vector<string> v2) {
    string head1 = v1[0], head2 = v2[0];
    
    transform(head1.begin(), head1.end(), head1.begin(), ::tolower);
    transform(head2.begin(), head2.end(), head2.begin(), ::tolower);
    
    if(head1 != head2) return head1 < head2;
    
    int num1 = stoi(v1[1]);
    int num2 = stoi(v2[1]);
    return num1 < num2;
}

vector<string> solution(vector<string> files) {
    vector<vector<string>> v;
    
    for(int i = 0; i < files.size(); i++) {
        string head, number, tail;
        bool numStart = false;
        
        for(int j = 0; j < files[i].size(); j++) {
            if(isdigit(files[i][j])) {
                numStart = true;
                number += files[i][j];
            } else {
                if(!numStart) {
                    head += files[i][j];
                } else {
                    tail += files[i].substr(j);
                    break;
                }
            }   
        }
        
        v.push_back({head, number, tail});
    }
    
    stable_sort(v.begin(), v.end(), compare);
    
    vector<string> result;
    for(const auto s: v) {
        result.push_back(s[0] + s[1] + s[2]);
    }
    
    return result;
}