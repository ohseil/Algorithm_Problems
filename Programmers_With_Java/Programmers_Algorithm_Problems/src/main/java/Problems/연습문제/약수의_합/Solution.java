package Problems.연습문제.약수의_합;

/*

    에라토스테네스의 체 알고리즘 사용.

 */

public class Solution {

    public void service() {

        int n = 12;

        int answer = solution(n);
        System.out.println(answer);

    }

    public int solution(int n) {

        int answer = 0;

        for (int num = 1; num * num <= n; num++) {

            if (n % num != 0)
                continue;

            if (num * num != n)
                answer += num;

            answer += (n / num);

        }

        return answer;
    }

}
