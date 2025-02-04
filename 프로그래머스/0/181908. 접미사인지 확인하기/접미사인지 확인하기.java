class Solution {
    public int solution(String my_string, String is_suffix) {
        int slen = is_suffix.length();
        int mlen = my_string.length();

        if(slen <= mlen) {
            String s = my_string.substring(mlen - slen);
            return s.equals(is_suffix) ? 1 : 0;
        } else return 0;
    }
}