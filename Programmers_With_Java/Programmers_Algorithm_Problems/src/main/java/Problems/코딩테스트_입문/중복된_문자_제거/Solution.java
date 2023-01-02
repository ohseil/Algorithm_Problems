package Problems.코딩테스트_입문.중복된_문자_제거;

import java.util.Set;
import java.util.TreeSet;

public class Solution {

    public void service() {

        String str = "We are the world";

        String answer = solution(str);
        System.out.println(answer);

    }

    public String solution(String my_string) {

        String answer = "";

        Set<Integer> set = new TreeSet<>();

        for (char ch : my_string.toCharArray()) {
            int idx = my_string.indexOf(ch);
            set.add(idx);
        }

        for (int idx : set) {
            answer += my_string.charAt(idx);
        }

        return answer;
    }
}
