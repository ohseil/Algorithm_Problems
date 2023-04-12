package Problems.연습문제.둘만의_암호;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Solution {

    final Map<Character, Integer> alphaIndexMap = new HashMap<>();
    final List<Character> alphaList = new ArrayList<>();

    public void service() {
        final String s = "aukks";
        final String skip = "wbqd";
        final int index = 5;

        final String answer = solution(s, skip, index);
        System.out.println(answer);
    }

    public String solution(final String s, final String skipStr, final int dist) {
        String answer = "";
        StringBuilder stringBuilder = new StringBuilder();

        setUp(skipStr);

        for (char ch : s.toCharArray()) {
            int idx = alphaIndexMap.get(ch);
            idx = (idx + dist) % alphaList.size();

            stringBuilder.append(alphaList.get(idx));
        }

        answer = stringBuilder.toString();
        return answer;
    }

    private void setUp(final String skipStr) {
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (!skipStr.contains(String.valueOf(ch))) {
                alphaList.add(ch);
                alphaIndexMap.put(ch, alphaList.size() - 1);
            }
        }
    }
}
