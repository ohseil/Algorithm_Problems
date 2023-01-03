package Problems.코딩테스트_입문.구슬을_나누는_경우의_수;

import java.math.BigInteger;

/*

    long 범위도 벗어나는 큰 숫자를 다루기 위해 BigInteger 사용

 */

public class Solution {

    public void service() {

        int balls = 3;
        int share = 2;

        int answer = solution(balls, share);
        System.out.println(answer);

    }

    public int solution(int balls, int share) {

        int answer = 0;

        BigInteger combination = BigInteger.valueOf(balls);

        for (int i = 1; i < balls; i++)
            combination = combination.multiply(BigInteger.valueOf(i));
        for (int i = 1; i <= (balls - share); i++)
            combination = combination.divide(BigInteger.valueOf(i));
        for (int i = 1; i <= share; i++)
            combination = combination.divide(BigInteger.valueOf(i));

        answer = combination.intValue();

        return answer;
    }

}
