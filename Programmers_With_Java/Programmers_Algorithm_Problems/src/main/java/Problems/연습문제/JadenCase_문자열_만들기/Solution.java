package Problems.연습문제.JadenCase_문자열_만들기;

public class Solution {

    public void service() {

        String s = "3people unFollowed me";

        String answer = solution(s);
        System.out.println(answer);

    }

    public String solution(String s) {

        String answer = "";

        answer = changeStrOnCond(s);

        return answer;
    }

    private String changeStrOnCond(String str) {

        StringBuilder stringBuilder = new StringBuilder();
        boolean isWord = false;

        for (char ch : str.toCharArray()) {

            if (ch != ' ') {

                if (('0' <= ch && ch <= '9') == true)
                    stringBuilder.append(ch);
                else {

                    if (isWord == false) {
                        stringBuilder.append(Character.toUpperCase(ch));
                    }
                    else
                        stringBuilder.append(Character.toLowerCase(ch));

                }

                isWord = true;

            }
            else {

                stringBuilder.append(ch);
                isWord = false;

            }

        }

        return stringBuilder.toString();
    }

}
