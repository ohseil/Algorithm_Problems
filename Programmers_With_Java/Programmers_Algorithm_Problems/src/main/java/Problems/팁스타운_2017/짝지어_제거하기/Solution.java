package Problems.팁스타운_2017.짝지어_제거하기;

import java.util.Deque;
import java.util.LinkedList;

public class Solution {

    public int solution(String s)
    {
        // stack을 사용했다.
        // 문자열의 문자를 차례대로 확인한다.
        // stack의 top문자와 비교해서 일치하면 stack에서 top을 제거한다.
        // 일치하지 않는다면 stack에 문자를 삽입한다.
        // 이 과정이 끝난 후 stack에 문자가 남아있다면 성공하지 못한 것이다.

        int answer = -1;

        Deque<Character> stack = new LinkedList<>();

        for (char ch : s.toCharArray()) {

            if (stack.isEmpty() == true || stack.getFirst() != ch)
                stack.push(ch);
            else
                stack.pollFirst();
        }

        if (stack.isEmpty() == true)
            answer = 1;
        else
            answer = 0;

        return answer;
    }

    public void service() {

        String s = "baabaa";

        int answer = solution(s);
        System.out.println(answer);
    }
}
