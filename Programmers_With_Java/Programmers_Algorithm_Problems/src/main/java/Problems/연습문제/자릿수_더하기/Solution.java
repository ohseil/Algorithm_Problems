package Problems.연습문제.자릿수_더하기;

public class Solution {

    public void service() {

        int n = 123;

        int answer = solution(n);
        System.out.println(answer);

    }

    public int solution(int n) {

        int answer = 0;

        while (n > 0) {

            answer += (n % 10);
            n /= 10;

        }

        return answer;
    }

}
