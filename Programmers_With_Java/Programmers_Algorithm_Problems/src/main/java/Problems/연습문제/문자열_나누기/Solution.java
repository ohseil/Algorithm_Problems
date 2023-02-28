package Problems.연습문제.문자열_나누기;

public class Solution {

    String str;
    int firstIdx = 0;

    public void service() {
        final String str = "banana";

        final int answer = solution(str);
        System.out.println(answer);
    }

    public int solution(final String s) {
        int answer = 0;
        str = s;

        while (firstIdx < str.length()) {
            divideStr();
            answer++;
        }
        return answer;
    }

    private void divideStr() {
        int endIdx = -1;
        int firstCnt = 0;
        int otherCnt = 0;

        for (int i = firstIdx; i < str.length(); i++) {
            if (str.charAt(i) == str.charAt(firstIdx)) {
                firstCnt++;
            } else {
                otherCnt++;
            }

            if (firstCnt == otherCnt) {
                endIdx = i;
                break;
            }
        }

        if (endIdx == -1) {
            firstIdx = str.length();
        } else {
            firstIdx = endIdx + 1;
        }
    }
}
