package Problems.연습문제.이상한_문자_만들기;

public class Solution {

    public void service() {

        String s = "try hello world";

        String answer = solution(s);
        System.out.println(answer);

    }

    public String solution(String s) {

        String answer = "";

        StringBuilder sb = new StringBuilder(s);

        int startWordIdx = 0;

        for (int i = 0; i < sb.length(); i++) {

            if (sb.charAt(i) == ' ') {
                startWordIdx = i + 1;
                continue;
            }

            if ((i - startWordIdx) % 2 == 0)
                sb.setCharAt(i, Character.toUpperCase(sb.charAt(i)));
            else
                sb.setCharAt(i, Character.toLowerCase(sb.charAt(i)));

        }

        answer = sb.toString();

        return answer;
    }

}
