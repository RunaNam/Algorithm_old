import java.util.*;

class Solution {
    public boolean solution(String[] phone_book) {
        String check = "_";
        Set<String> phoneNumbers = new HashSet<>(Arrays.asList(phone_book));

        for (String number : phone_book) {
            String tmp = "";
            phoneNumbers.remove(number);
            for (int i = 0; i < number.length(); i++) {
                tmp += number.charAt(i);
                if (phoneNumbers.contains(tmp)) {
                    return false;
                }
            }
            phoneNumbers.add(number);
        }

        return true;
    }
}