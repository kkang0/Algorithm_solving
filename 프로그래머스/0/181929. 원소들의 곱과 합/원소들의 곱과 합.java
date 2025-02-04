class Solution {
    public int solution(int[] num_list) {
        int mul = 1;
        int sum = 0;
        
        for(int num: num_list) {
            mul *= num;
            sum += num;;
        }
            
        return mul < Math.pow(sum, 2) ? 1 : 0;
    }
}