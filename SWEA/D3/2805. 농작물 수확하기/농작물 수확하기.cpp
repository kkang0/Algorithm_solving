#include <iostream>
using namespace std;

int arr[50][50];

int main(void) {
    int T;
    cin >> T;
    
    for(int test_case = 1; test_case <= T; test_case++) {
    	int n;
        cin >> n;
        
        for(int i = 0; i < n; i++) {
        	for(int j = 0; j < n; j++) {
            	scanf("%1d", &arr[i][j]);
            }
        }
        
        int result = 0;
        for(int i = 0; i < n / 2; i++) {
        	for(int j = n / 2 - i; j <= n / 2 + i; j++) {
            	result += arr[i][j];
            }
        }
        
        for (int i = 0; i <= n / 2; i++) {
            for (int j = i; j < n - i; j++) {
                result += arr[i + n / 2][j];
            }
        }
        
        cout << "#" << test_case << " " << result << endl;
    }
	return 0;
}