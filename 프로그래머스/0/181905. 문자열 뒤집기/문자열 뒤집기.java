class Solution {
    public String solution(String my_string, int s, int e) {
        StringBuilder str = new StringBuilder(my_string.substring(s, e + 1));
        str.reverse();
        return my_string.substring(0, s) + str + my_string.substring(e + 1);
    }
}