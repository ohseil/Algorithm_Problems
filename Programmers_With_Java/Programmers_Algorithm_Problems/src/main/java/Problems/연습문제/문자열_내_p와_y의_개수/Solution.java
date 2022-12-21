package Problems.연습문제.문자열_내_p와_y의_개수;

public class Solution {

    public void service() {

        String s = "pPoooyY";

        boolean answer = solution(s);
        System.out.println(answer);

    }

    boolean solution(String s) {

        boolean answer;

        int ratio = 0;

        for (char ch : s.toCharArray()) {
            if (ch == 'p' || ch == 'P') ratio++;
            else if (ch == 'y' || ch == 'Y') ratio--;
        }

        if (ratio == 0) answer = true;
        else answer = false;

        return answer;
    }

}
