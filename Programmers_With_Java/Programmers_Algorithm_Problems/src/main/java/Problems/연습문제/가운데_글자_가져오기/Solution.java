package Problems.연습문제.가운데_글자_가져오기;

public class Solution {

    public void service() {

        String s = "abcde";

        String answer = solution(s);
        System.out.println(answer);

    }

    public String solution(String s) {

        String answer = "";

        if (s.length() % 2 == 0) {
            answer += s.charAt(s.length() / 2 - 1);
            answer += s.charAt(s.length() /2);
        }
        else
            answer += s.charAt(s.length() / 2);

        return answer;
    }

}
