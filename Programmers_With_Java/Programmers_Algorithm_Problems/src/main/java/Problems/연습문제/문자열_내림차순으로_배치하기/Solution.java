package Problems.연습문제.문자열_내림차순으로_배치하기;

import java.util.*;

public class Solution {

    private List<Character> charList;
    private StringBuilder stringBuilder;

    public void service() {

        String s = "Zbcdefg";

        String answer = solution(s);
        System.out.println(answer);

    }

    public String solution(String s) {

        String answer = "";

        init(s.length());
        makeStrToCharList(s);

        Collections.sort(charList, Collections.reverseOrder());

        makeStrUsingCharList();

        answer = stringBuilder.toString();

        return answer;
    }

    private void init(final int len) {
        charList = new ArrayList<>(len);
        stringBuilder = new StringBuilder();
    }

    private void makeStrToCharList(final String str) {
        for (int i =0 ; i < str.length(); i++)
            charList.add(str.charAt(i));
    }

    private void makeStrUsingCharList() {
        for (char ch : charList)
            stringBuilder.append(ch);
    }

}
