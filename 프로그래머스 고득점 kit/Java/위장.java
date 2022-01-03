import java.util.*;

class Solution {
    public int solution(String[][] clothes) {
        int answer = 1;
        Map<String, Integer> closet = new HashMap<>();

        for (String[] cloth : clothes) {
            closet.put(cloth[1], closet.getOrDefault(cloth[1], 0) + 1);
        }

        for (String cloth : closet.keySet()) {
            answer *= closet.get(cloth) + 1;
        }
        return answer - 1;
    }
}