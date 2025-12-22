import java.util.HashMap;
import java.util.Map;

class Solution {
    public int solution(int[] array) {
        Map<Integer, Integer> map = new HashMap<>();

        for (int num : array) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }

        int maxCount = 0;
        int answer = -1;

        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            int value = entry.getValue();
            int key = entry.getKey();

            if (value > maxCount) {
                maxCount = value;
                answer = key;
            } else if (value == maxCount) {
                answer = -1;
            }
        }

        return answer;
    }
}