package Problems.연습문제.x만큼_간격이_있는_n개의_숫자;

public class Solution {

    public void service() {

        int x = 2;
        int n = 5;

        long[] answer = solution(x, n);

        for (long a : answer)
            System.out.print(a + " ");

    }

    public long[] solution(int x, int n) {

        long[] answer = new long[n];

        for (int i = 0; i < n; i++)
            answer[i] = x + ((long)x * i);

        return answer;
    }

}
