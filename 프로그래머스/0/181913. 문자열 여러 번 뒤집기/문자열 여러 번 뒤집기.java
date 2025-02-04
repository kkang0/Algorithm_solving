class Solution {
    public String solution(String my_string, int[][] queries) {
        StringBuilder str = new StringBuilder(my_string);
        
        for(int[] query: queries) {
            int start = query[0];
            int end = query[1];
            
            String r = new StringBuilder(str.substring(start, end + 1)).reverse().toString();
            str.replace(start, end + 1, r);
        }
        
        return str.toString();
    }
}