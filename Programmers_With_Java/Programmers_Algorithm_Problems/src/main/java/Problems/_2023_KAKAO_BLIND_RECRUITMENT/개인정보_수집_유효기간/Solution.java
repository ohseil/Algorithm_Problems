package Problems._2023_KAKAO_BLIND_RECRUITMENT.개인정보_수집_유효기간;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Solution {

    private final Map<Character, Integer> map = new HashMap<>();

    private int dayOfToday;

    public void service() {
        String today = "2022.05.19";
        String[] terms = {"A 6", "B 12", "C 3"};
        String[] privacies = {"2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C"};

        int[] answer = solution(today, terms, privacies);
        for (int a : answer) {
            System.out.print(a + " ");
        }
    }

    public int[] solution(final String today, final String[] terms, final String[] privacies) {
        int[] answer = {};

        dayOfToday = dateToDay(today);
        makeTermMap(terms);
        List<Integer> expiredPrivacies = checkExpiredPrivacy(privacies);

        answer = new int[expiredPrivacies.size()];

        for (int i = 0; i < expiredPrivacies.size(); i++) {
            answer[i] = expiredPrivacies.get(i);
        }
        return answer;
    }

    private int dateToDay(final String date) {
        int year = Integer.parseInt(date.substring(0, 4));
        int month = Integer.parseInt(date.substring(5, 7));
        int day = Integer.parseInt(date.substring(8));

        return day + (month * 28) + (year * 12 * 28);
    }

    private void makeTermMap(final String[] terms) {
        for (String term : terms) {
            char type = term.substring(0, 1).toCharArray()[0];
            int expirationPeriod = Integer.parseInt(term.substring(2));

            map.put(type, expirationPeriod * 28);
        }
    }

    private List<Integer> checkExpiredPrivacy(final String[] privacies) {
        List<Integer> expiredPrivacies = new ArrayList<>();

        for (int num = 0; num < privacies.length; num++) {
            String privacy = privacies[num];

            String expirationDate = privacy.substring(0, privacy.indexOf(' '));
            char termType = privacy.substring(privacy.indexOf(' ') + 1).toCharArray()[0];
            int dayOfExpirationDate = dateToDay(expirationDate);

            if (dayOfExpirationDate + map.get(termType) <= dayOfToday) {
                expiredPrivacies.add(num + 1);
            }
        }
        return expiredPrivacies;
    }
}
