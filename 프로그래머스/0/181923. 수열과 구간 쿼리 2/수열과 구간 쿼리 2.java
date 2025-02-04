import java.util.*;

class Solution {
    public ArrayList solution(int[] arr, int[][] queries) {
        ArrayList<Integer> list = new ArrayList<>();
        
        for(int i = 0; i < queries.length; i++) {
            int s = queries[i][0];
            int e = queries[i][1];
            int k = queries[i][2];
            
            int min = Integer.MAX_VALUE;
            for(int t = s; t <= e; t++) {
                if(arr[t] < min && arr[t] > k) {
                    min = arr[t];
                }
            }
            
            list.add(min == Integer.MAX_VALUE ? -1 : min);
        }
        
        return list;
    }
}