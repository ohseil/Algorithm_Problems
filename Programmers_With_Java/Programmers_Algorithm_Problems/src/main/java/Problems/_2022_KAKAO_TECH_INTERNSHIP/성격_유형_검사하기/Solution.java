package Problems._2022_KAKAO_TECH_INTERNSHIP.성격_유형_검사하기;

import java.util.HashMap;
import java.util.Map;

public class Solution {

    private static final String[] INDICATORS = {"RT", "CF", "JM", "AN"};

    private Map<Character, Integer> scoreMap;

    public Solution() {
        scoreMap = new HashMap<>();
    }

    public void service() {

        String[] survey = {"AN", "CF", "MJ", "RT", "NA"};
        int[] choices = {5,3,2,7,5};

        String answer = solution(survey, choices);

        System.out.println(answer);

    }

    public String solution(String[] survey, int[] choices) {

        String answer = "";

        calculateScoreInSurvey(survey, choices);

        answer = confirmTypeInIndicators();

        return answer;
    }

    private void calculateScoreInSurvey(final String[] surveys, final int[] choices) {

        for (int i = 0; i < surveys.length; i++) {

            char personalType1 = surveys[i].charAt(0);
            char personalType2 = surveys[i].charAt(1);
            int choice = choices[i];

            if (choice < 4) scoreMap.put(personalType1, scoreMap.getOrDefault(personalType1, 0) + (4 - choice));
            else scoreMap.put(personalType2, scoreMap.getOrDefault(personalType2, 0) + (choice - 4));

        }

    }

    private String confirmTypeInIndicators() {

        StringBuilder stringBuilder = new StringBuilder();

        for (String indicator : INDICATORS) {

            char personalType1 = indicator.charAt(0);
            char personalType2 = indicator.charAt(1);

            int typeScore1 = scoreMap.getOrDefault(personalType1, 0);
            int typeScore2 = scoreMap.getOrDefault(personalType2, 0);

            if (typeScore1 >= typeScore2) stringBuilder.append(personalType1);
            else stringBuilder.append(personalType2);

        }

        return stringBuilder.toString();
    }

}
