class Solution {
    public int solution(int a, int b) {
        int s = Integer.parseInt("" + a + b);
        int p = 2 * a * b;
        
        return s > p ? s : p;
    }
}