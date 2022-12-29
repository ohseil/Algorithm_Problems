package Problems.연습문제.수박수박수박수박수박수;

public class Solution {

    private StringBuilder stringBuilder;

    public void service() {

        int n = 3;

        String answer = solution(n);
        System.out.println(answer);

    }

    public String solution(int n) {

        String answer = "";

        init();

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) stringBuilder.append('수');
            else stringBuilder.append('박');
        }

        answer = stringBuilder.toString();

        return answer;
    }

    private void init() {
        stringBuilder = new StringBuilder();
    }

}
