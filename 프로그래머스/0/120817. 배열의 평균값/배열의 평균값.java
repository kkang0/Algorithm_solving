class Solution {
    public double solution(int[] numbers) {
        double result = 0;
        for(int n: numbers) result += n;
        
        return result / numbers.length;
    }
}