class Solution {
    public int solution(int price) {
        int result = price;
        if(price >= 500000) result *= 0.8;
        else if(price >= 300000) result *= 0.9;
        else if(price >= 100000) result *= 0.95;
        
        return result;
    }
}