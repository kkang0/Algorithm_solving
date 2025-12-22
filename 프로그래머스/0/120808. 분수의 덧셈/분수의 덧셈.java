class Solution {
    public int[] solution(int numer1, int denom1, int numer2, int denom2) {
        int numer = numer2 * denom1 + numer1 * denom2;
        int denom = denom1 * denom2;
        
        int max = 1;
        for(int i = 1; i <= numer && i <= denom; i++) {
            if(denom % i == 0 && numer % i == 0) max = i;
        }
        
        numer /= max;
        denom /= max;
        
        int[] result = {numer, denom};
        return result;
    }
}