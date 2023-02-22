package Problems.연습문제.푸드_파이트_대회;

public class Solution {

    public void service() {
        final int[] foods = {1,3,4,6};
        final String answer = solution(foods);
        System.out.println(answer);
    }

    public String solution(final int[] foods) {
        String answer = "";
        StringBuilder stringBuilder = new StringBuilder();

        for (int i = 1; i < foods.length; i++) {
            for (int j = 0; j < foods[i] / 2; j++) {
                stringBuilder.append(i);
            }
        }

        answer = (stringBuilder.toString() + "0" + stringBuilder.reverse());
        return answer;
    }
}
