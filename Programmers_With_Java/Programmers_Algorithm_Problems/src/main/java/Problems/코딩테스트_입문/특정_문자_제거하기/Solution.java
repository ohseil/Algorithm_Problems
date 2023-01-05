package Problems.코딩테스트_입문.특정_문자_제거하기;

public class Solution {

    public void service() {

        String my_string = "abcdef";
        String letter = "f";

        String answer = solution(my_string, letter);
        System.out.println(answer);

    }

    public String solution(String my_string, String letter) {

        String answer = "";

        StringBuilder stringBuilder = new StringBuilder();

        for (char ch : my_string.toCharArray())
            if (ch != letter.charAt(0))
                stringBuilder.append(ch);

        answer = stringBuilder.toString();

        return answer;
    }

}
