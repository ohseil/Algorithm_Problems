package Problems.연습문제.문자열을_정수로_바꾸기;

public class Solution {

    public void service() {

        String s = "-1234";

        int answer = solution(s);
        System.out.println(answer);

    }

    public int solution(String s) {

        int answer = 0;

        if (s.charAt(0) == '-') answer = -Integer.parseInt(s.substring(1));
        else if (s.charAt(0) == '+') answer = Integer.parseInt(s.substring(1));
        else answer = Integer.parseInt(s);

        return answer;
    }

}
