import java.util.*;

class Solution {
    public String[] solution(String my_string) {
        ArrayList<String> answer = new ArrayList<>();
        
        for (int i = 0; i < my_string.length(); i++) {
            answer.add(my_string.substring(i));
        }
        
        Collections.sort(answer);
        
        String[] result = new String[answer.size()];
        for (int i = 0; i < answer.size(); i++)
            result[i] = answer.get(i);
        
        return result;
    }
}