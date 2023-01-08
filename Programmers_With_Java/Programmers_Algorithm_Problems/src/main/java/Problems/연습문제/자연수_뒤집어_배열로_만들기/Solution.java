package Problems.연습문제.자연수_뒤집어_배열로_만들기;

public class Solution {

    public void service() {

        long n = 12345;

        int[] answer = solution(n);
        for (int a : answer)
            System.out.print(a + " ");

    }

    public int[] solution(long n) {

        int[] answer = {};

        String num = String.valueOf(n);

        answer = new int[num.length()];

        for (int i = 0; i < num.length(); i++)
            answer[i] = (int)num.charAt(num.length() - 1 - i) - 48;

        return answer;
    }

}
