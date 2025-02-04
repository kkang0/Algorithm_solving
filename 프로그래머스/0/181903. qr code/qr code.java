class Solution {
    public String solution(int q, int r, String code) {
        String s = "";
        for(int i = 0; i < code.length(); i++) {
            if(i % q == r) s += code.charAt(i);
        }

        return s;
    }
}