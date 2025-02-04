import java.util.*;

class Solution {
    public ArrayList<Integer> solution(String[] intStrs, int k, int s, int l) {
        ArrayList<Integer> answer = new ArrayList<>();
        
        for(int i = 0; i < intStrs.length; i++) {
            String str = intStrs[i].substring(s, s + l);
            int num = Integer.parseInt(str);
            if(num > k) answer.add(num);
        }
        return answer;
    }
}