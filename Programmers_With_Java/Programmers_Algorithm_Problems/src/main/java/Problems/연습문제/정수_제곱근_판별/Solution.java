package Problems.연습문제.정수_제곱근_판별;

public class Solution {

    public void service() {

        long n = 121;

        long answer = solution(n);
        System.out.println(answer);

    }

    public long solution(long n) {

        long answer = -1;

        double sqrtNum = Math.sqrt(n);
        long integralPart = (long)sqrtNum;

        if (sqrtNum - (double)integralPart == 0)
            answer = (integralPart + 1) * (integralPart + 1);

        return answer;
    }

}
