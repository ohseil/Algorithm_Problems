package Problems.연습문제.짝수와_홀수;

public class Solution {

    public void service() {

        int num = 3;

        String answer = solution(num);
        System.out.println(answer);

    }

    public String solution(int num) {

        String answer = "";

        if (num % 2 == 0) answer = "Even";
        else answer = "Odd";

        return answer;
    }

}
