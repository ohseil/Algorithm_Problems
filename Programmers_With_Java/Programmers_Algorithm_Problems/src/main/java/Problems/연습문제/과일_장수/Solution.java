package Problems.연습문제.과일_장수;

import java.util.Arrays;

public class Solution {

    public void service() {
        final int k = 3;
        final int m = 4;
        final int[] scores = {1,2,3,1,2,3,1};

        final int answer = solution(k, m, scores);
        System.out.println(answer);
    }

    public int solution(final int k, final int m, final int[] scores) {
        int answer = 0;

        Arrays.sort(scores);

        for (int i = scores.length - m; i >= 0; i -= m) {
            answer += (scores[i] * m);
        }
        return answer;
    }
}
