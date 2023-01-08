package Problems.연습문제.정수_내림차순으로_배치하기;

import java.util.Arrays;

public class Solution {

    public void service() {

        long n = 118372;

        long answer = solution(n);
        System.out.println(answer);

    }

    public long solution(long n) {

        long answer = 0;

        char[] digitArr = String.valueOf(n).toCharArray();
        char[] reverseDigitArr = new char[digitArr.length];

        Arrays.sort(digitArr);

        for (int i = 0; i < digitArr.length; i++)
            reverseDigitArr[i] = digitArr[digitArr.length - 1 - i];

        answer = Long.parseLong(String.valueOf(reverseDigitArr));

        return answer;
    }

}
