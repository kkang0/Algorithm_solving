#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<vector<int>> v(n, vector<int>(n, 0));
    
    int x = 0;
    int y = 0;
    int cnt = 1;
    int dir = 0;
    
    for (int i = n; i > 0; i -= 3) {
        for (int j = 0; j < i; j++) {
            v[y++][x] = cnt++;
        }
        y--; x++;
        
        for (int j = 0; j < i - 1; j++) {
            v[y][x++] = cnt++;
        }
        x -= 2; y--;
        
        for (int j = 0; j < i - 2; j++) {
            v[y--][x--] = cnt++;
        }
        y += 2; x++;
    }
    
    vector<int> result;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            result.push_back(v[i][j]);
        }
    }
    
    return result;
}