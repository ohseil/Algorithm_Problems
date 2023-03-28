package Problems.연습문제.카드_뭉치;

public class Solution {

    public void service() {
        final String[] cards1 = {"i", "drink", "water"};
        final String[] cards2 = {"want", "to"};
        final String[] goal = {"i", "want", "to", "drink", "water"};

        final String answer = solution(cards1, cards2, goal);
        System.out.println(answer);
    }

    public String solution(String[] cards1, String[] cards2, String[] goal) {
        String answer = "Yes";
        int idx1 = 0;
        int idx2 = 0;

        for (String word : goal) {
            if (idx1 < cards1.length && cards1[idx1].equals(word)) {
                idx1++;
            } else if (idx2 < cards2.length && cards2[idx2].equals(word)) {
                idx2++;
            } else {
                answer = "No";
                break;
            }
        }
        return answer;
    }
}
