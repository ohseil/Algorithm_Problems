package Problems.코딩테스트_입문.중복된_문자_제거;

import java.util.HashSet;
import java.util.Set;

public class Solution {

    public void service() {

        String str = "We are the world";

        String answer = solution(str);
        System.out.println(answer);

    }

    public String solution(String my_string) {

        String answer = "";

        Set<Character> charSet = new HashSet<>();

        for (int i = 0; i < my_string.length(); i++) {

            char ch = my_string.charAt(i);

            if (charSet.contains(ch) == true)
                continue;

            answer += ch;
            charSet.add(ch);

        }

        return answer;
    }
}
