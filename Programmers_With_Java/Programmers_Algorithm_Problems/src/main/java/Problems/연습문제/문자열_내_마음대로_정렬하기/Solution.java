package Problems.연습문제.문자열_내_마음대로_정렬하기;

import java.util.Arrays;

public class Solution {

    public void service() {

        String[] strings = {"sun", "bed", "car"};
        int n = 1;

        String[] answer = solution(strings, n);
        for (String a : answer)
            System.out.print(a + " ");

    }

    public String[] solution(String[] strings, int n) {

        String[] answer = {};

        Arrays.sort(strings, (String o1, String o2) -> {
                                if (o1.charAt(n) < o2.charAt(n)) return -1;
                                else if (o1.charAt(n) == o2.charAt(n)) return o1.compareTo(o2);
                                return 1;
                            });

        answer = strings;

        return answer;
    }

}
