package Problems.연습문제.대충_만든_자판;

import java.util.Map;
import java.util.HashMap;

/**
 * 전체 키 정보를 한 번 확인하여 각 알파벳을 입력하기 위해 눌러야 하는 최소 횟수를 Hash Map에 저장한다.
 * 문제로 주어지는 각 문자열 마다 포함된 문자들을 저장해 놓았던 map을 참조하여 눌러야 하는 최소 횟수를 구해서 더한다.
 */

public class Solution {

    final Map<Character, Integer> minPressCntMap = new HashMap<>();

    public void service() {
        String[] keymap = {"ABACD", "BCEFD"};
        String[] targets = {"ABCD", "AABB"};

        int[] answer = solution(keymap, targets);
        for (int a : answer) {
            System.out.print(a + " ");
        }
    }

    public int[] solution(final String[] keymap, final String[] targets) {
        int[] answer = new int[targets.length];

        makeMinPressCntMap(keymap);

        for (int i = 0; i < targets.length; i++) {
            int totalPressCnt = 0;

            for (char ch : targets[i].toCharArray()) {
                if (!minPressCntMap.containsKey(ch)) {
                    totalPressCnt = -1;
                    break;
                }
                totalPressCnt += minPressCntMap.get(ch);
            }
            answer[i] = totalPressCnt;
        }
        return answer;
    }

    private void makeMinPressCntMap(final String[] keymap) {
        for (String key : keymap) {
            for (int i = 0; i < key.length(); i++) {
                char alphabet = key.charAt(i);
                int pressCnt = i + 1;

                int minPressCnt = minPressCntMap.getOrDefault(alphabet, 100);

                if (pressCnt < minPressCnt) {
                    minPressCntMap.put(alphabet, pressCnt);
                }
            }
        }
    }
}
