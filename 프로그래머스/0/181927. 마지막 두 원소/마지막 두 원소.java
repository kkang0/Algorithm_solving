import java.util.*;

class Solution {
    public List solution(int[] num_list) {
        List<Integer> answer = new ArrayList<>();
        
        int before = num_list[num_list.length - 2];
        int last = num_list[num_list.length - 1];
        
        for(int i = 0; i < num_list.length; i++) {
            answer.add(num_list[i]);
        }
        
        if(last > before) answer.add(last - before);
        else answer.add(last * 2);
        
        return answer;
    }
}