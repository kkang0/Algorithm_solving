import java.util.*;

class Solution {
    public int solution(int a, int b, int c, int d) {
        int[] v = {a, b, c, d};
        
        Arrays.sort(v);
        
        int result = 0;
        if(v[0] == v[3]) result = 1111 * v[0];
        else if (v[0] == v[2]) result = (10 * v[0] + v[3]) * (10 * v[0] + v[3]);
        else if (v[1] == v[3]) result = (10 * v[1] + v[0]) * (10 * v[1] + v[0]);
        else if (v[0] == v[1]) {
            if(v[2] == v[3]) result = (v[0] + v[2]) * Math.abs(v[0] - v[2]);
            else result = v[2] * v[3];
        }
        else if (v[1] == v[2]) result = v[0] * v[3];
        else if (v[2] == v[3]) result =  v[0] * v[1];
        else result = v[0];
        
        return result;
    }
}