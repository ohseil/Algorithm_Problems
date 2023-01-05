package Problems.연습문제.크기가_작은_부분_문자열;

public class Solution {

    public void service() {

        String t = "3141592";
        String p = "271";

        int answer = solution(t, p);
        System.out.println(answer);

    }

    public int solution(String t, String p) {

        int answer = 0;

        long pNum = Long.valueOf(p);

        for (int i = 0; i < t.length() - p.length() + 1; i++) {

            String tSub = t.substring(i, i + p.length());
            long tNum = Long.valueOf(tSub);

            if (tNum <= pNum)
                answer++;

        }

        return answer;
    }

}
