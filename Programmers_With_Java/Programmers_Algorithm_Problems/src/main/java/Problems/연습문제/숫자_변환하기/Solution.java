package Problems.연습문제.숫자_변환하기;

/**
 * dp 사용
 */

public class Solution {

    public void service() {
        final int x = 10;
        final int y = 40;
        final int n = 5;

        final int answer = solution(x, y, n);
        System.out.println(answer);
    }

    public int solution(int x, int y, int n) {
        int answer = -1;

        final int[] dp = new int[1000001];
        dp[x] = 1;

        for (int i = x; i < y; i++) {
            if (dp[i] == 0) {
                continue;
            }

            if (i + n <= y && (dp[i + n] == 0 || dp[i] + 1 < dp[i + n])) {
                dp[i + n] = dp[i] + 1;
            }
            if (i * 2 <= y && (dp[i * 2] == 0 || dp[i] + 1 < dp[i * 2])) {
                dp[i * 2] = dp[i] + 1;
            }
            if (i * 3 <= y && (dp[i * 3] == 0 || dp[i] + 1 < dp[i * 3])) {
                dp[i * 3] = dp[i] + 1;
            }
        }

        if (dp[y] != 0) {
            answer = dp[y] - 1;
        }
        return answer;
    }
}
