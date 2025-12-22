import java.util.*;

class Solution {
    public int solution(int[] array) {
        Arrays.sort(array);
        
        int n = array.length;
        return array[n / 2];
    }
}