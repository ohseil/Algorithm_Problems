package Problems.연습문제.시저_암호;

public class Solution {

    public void service() {

        String s = "a B z";
        int n = 4;

        String answer = solution(s, n);
        System.out.println(answer);

    }

    public String solution(String s, int n) {

        String answer = "";

        StringBuilder stringBuilder = new StringBuilder(s);

        for (int i = 0; i < s.length(); i++) {

            char ch = stringBuilder.charAt(i);

            if ('a' <= ch && ch <= 'z') {
                ch -= 'a';
                ch = (char)((ch + n) % 26 + 'a');
            }
            else if ('A' <= ch && ch <= 'Z') {
                ch -= 'A';
                ch = (char)((ch + n) % 26 + 'A');
            }

            stringBuilder.setCharAt(i, ch);

        }

        answer = stringBuilder.toString();

        return answer;
    }

}
