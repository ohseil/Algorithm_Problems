package Problems.연습문제.문자열_다루기_기본;

public class Solution {

    public void service() {

        String s = "a234";

        boolean answer = solution(s);
        System.out.println(answer);

    }

    public boolean solution(String s) {

        boolean answer = true;

        if (s.length() != 4 && s.length() != 6) {
            answer = false;
        }
        else {

            for (char ch : s.toCharArray()) {
                if (('0' <= ch && ch <= '9') == false) {
                    answer = false;
                    break;
                }
            }

        }

        return answer;
    }

}
