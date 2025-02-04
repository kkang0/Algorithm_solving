import java.util.*;

class Solution {
    public List solution(int l, int r) {
        List<Integer> list = new ArrayList<>();
        
        for(int i = l; i <= r; i++) {
            String s = i + "";
            boolean flag = true;
            
            for(char c: s.toCharArray()) {
                if(c != '0' && c != '5') flag = false;
            }
            
            if(flag) list.add(i);
        }
        
        if(list.isEmpty()) list.add(-1);
        
        return list;
    }
}