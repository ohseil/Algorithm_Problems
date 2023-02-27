package Problems.연습문제.명예의_전당;

import java.util.*;

public class Solution {

    public void service() {
        final int k = 3;
        final int[] scores = {10, 100, 20, 150, 1, 100, 200};

        final int[] answer = solution(k, scores);
        for (int a : answer) {
            System.out.print(a + " ");
        }
    }

    public int[] solution(final int k, final int[] scores) {
        int[] answer = new int[scores.length];
        Queue<Integer> queue = new PriorityQueue<>();

        for (int i = 0; i < scores.length; i++) {
            queue.add(scores[i]);

            if (queue.size() > k) {
                queue.poll();
            }

            answer[i] = queue.peek();
        }
        return answer;
    }
}
