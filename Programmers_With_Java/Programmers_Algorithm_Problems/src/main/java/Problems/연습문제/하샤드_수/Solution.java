package Problems.연습문제.하샤드_수;

public class Solution {

    public void service() {

        int x = 10;

        boolean answer = solution(x);
        System.out.println(answer);

    }

    public boolean solution(int x) {

        boolean answer;

        int num = x;
        int divisor = 0;

        while (x > 0) {
            divisor += (x % 10);
            x /= 10;
        }

        if (num % divisor == 0) answer = true;
        else answer = false;

        return answer;
    }

}
