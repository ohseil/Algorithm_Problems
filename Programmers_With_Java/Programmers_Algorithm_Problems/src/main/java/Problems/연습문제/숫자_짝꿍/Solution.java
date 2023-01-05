package Problems.연습문제.숫자_짝꿍;

import java.util.Map;
import java.util.TreeMap;

/*

    X와 Y에서 각 자리의 숫자들의 개수를 센다.
    가장 큰 숫자부터 X에서의 개수와 Y에서의 개수를 비교해서
    더 작은 개수만큼 문자열에 추가해 나간다.

 */

public class Solution {

    public void service() {

        String X = "100";
        String Y = "2345";

        String answer = solution(X, Y);
        System.out.println(answer);
    }

    public String solution(String X, String Y) {

        String answer = "";

        StringBuilder stringBuilder = new StringBuilder();

        Map<Integer, Integer> xNumCntMap = new TreeMap<>();
        Map<Integer, Integer> yNumCntMap = new TreeMap<>();

        for (char ch : X.toCharArray())
            xNumCntMap.put(-(int)ch, xNumCntMap.getOrDefault(-(int)ch, 0) + 1);
        for (char ch : Y.toCharArray())
            yNumCntMap.put(-(int)ch, yNumCntMap.getOrDefault(-(int)ch, 0) + 1);

        for (int num : xNumCntMap.keySet()) {

            int xNumCnt = xNumCntMap.get(num);
            int yNumCnt = yNumCntMap.getOrDefault(num, 0);

            int minCnt = Math.min(xNumCnt, yNumCnt);

            for (int i = 0; i < minCnt; i++)
                stringBuilder.append((char)-num);

        }

        if (stringBuilder.length() == 0) answer = "-1";
        else if (stringBuilder.charAt(0) == '0') answer = "0";
        else answer = stringBuilder.toString();

        return answer;
    }

}
