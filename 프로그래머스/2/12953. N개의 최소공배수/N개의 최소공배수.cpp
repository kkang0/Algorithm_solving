#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	if(b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a,int b) {
    return a * b / gcd(a, b);
}

int solution(vector<int> arr) {
    while(arr.size() > 1) {
        int a = arr[0];
        int b = arr[1];
        int l = lcm(a, b);
        arr.erase(arr.begin(), arr.begin() + 2);
        arr.insert(arr.begin(), l);
    }
    
    return arr[0];
}