package Problems.연습문제.가장_가까운_같은_글자;

import java.util.HashMap;
import java.util.Map;

/*

    문자를 처음부터 끝까지 순회한다.
    각 문자마다 문자의 마지막 index를 hash map을 이용해서 저장하고
    현재 문자의 마지막 index가 map에 없다면 -1로 저장하고
    있다면 현재 index - 문자의 마지막 index로 저장한다.

 */

public class Solution {

    private Map<Character, Integer> lastIdxOfCharMap;

    public void service() {

        String str = "banana";

        int[] answerList = solution(str);
        for (int answer : answerList)
            System.out.print(answer + " ");

    }

    public int[] solution(String s) {

        int[] answer = new int[s.length()];

        init();

        for (int i = 0; i < s.length(); i++) {

            char ch = s.charAt(i);

            int lastIdx = lastIdxOfCharMap.getOrDefault(ch, -1);

            if (lastIdx == -1)
                answer[i] = -1;
            else
                answer[i] = i - lastIdx;

            lastIdxOfCharMap.put(ch, i);

        }

        return answer;
    }

    private void init() {
        lastIdxOfCharMap = new HashMap<>();
    }

}
