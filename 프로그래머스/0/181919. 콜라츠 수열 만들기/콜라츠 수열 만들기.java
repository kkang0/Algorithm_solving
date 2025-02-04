import java.util.*;

class Solution {
    public List solution(int n) {
        List<Integer> list = new ArrayList<>();
        
        while(true) {
            if(n == 1) {
                list.add(n);
                break;
            }
            
            if(n % 2 == 0) {
                list.add(n);
                n /= 2;
            }
            else if(n % 2 != 0) {
                list.add(n);
                n = 3 * n + 1;
            };
        }
        
        return list;
    }
}