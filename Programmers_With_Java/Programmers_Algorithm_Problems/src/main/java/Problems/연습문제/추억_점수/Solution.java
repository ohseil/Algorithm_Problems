package Problems.연습문제.추억_점수;

import java.util.HashMap;
import java.util.Map;

public class Solution {

    final Map<String, Integer> scoreOfNames = new HashMap<>();

    public void service() {
        final String[] names = {"may", "kein", "kain", "radi"};
        final int[] yearnings = {5,10,1,3};
        final String[][] photos = {{"may", "kein", "kain", "radi"}, {"may", "kein", "brin", "deny"}, {"kon", "kain", "may", "coni"}};

        final int[] answer = solution(names, yearnings, photos);
        for (int a : answer) {
            System.out.print(a + " ");
        }
    }

    public int[] solution(String[] name, int[] yearning, String[][] photo) {
        int[] answer = new int[photo.length];

        makeScoreMap(name, yearning);

        for (int i = 0; i < photo.length; i++) {
            String[] personNames = photo[i];
            int score = 0;

            for (String personName : personNames) {
                score += scoreOfNames.getOrDefault(personName, 0);
            }
            answer[i] = score;
        }
        return answer;
    }

    private void makeScoreMap(final String[] names, final int[] scores) {
        for (int i = 0; i < names.length; i++) {
            scoreOfNames.put(names[i], scores[i]);
        }
    }
}
