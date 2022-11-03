package Problems.Summer_Winter_Coding_to_2018.점프와_순간_이동;

public class Solution {

    private int getJumpCountInMove(int n) {
        if (n == 0) return 0;
        if (n % 2 == 0) return getJumpCountInMove(n / 2);
        else return getJumpCountInMove(n - 1) + 1;
    }

    public int solution(int n) {

        // 가장 연료를 적게 사용하기 위해서는
        // 순간이동으로 최대한 많이 이동해야 한다는 의미다.

        // n에 도달하기 바로 직전의 위치를 생각해 보면,
        // n에 도달하기 위해 마지막으로 순간이동을 썼을 때,
        // 가장 많이 이동하는 경우는
        // n이 짝수일 때는 n / 2 위치에서 순간이동,
        // n이 홀수일 때는 (n-1)/2 위치에서 순간이동 후에 n-1 위치에서 한칸 점프하는 경우다.

        // 마찬가지로 n/2 또는 (n-1)/2 위치로 이동하는데 가장 많은 범위를 순간이동하는 경우도 같다.

        // n 위치에서 시작해서 반대로 이동해 나간다.
        // n 위치에서 시작해서 짝수인 경우에는 순간이동,
        // 홀수인 경우에는 -1 칸 점프해서 짝수로 만들고 순간이동 한다.

        int ans = getJumpCountInMove(n);

        return ans;
    }

    public void service() {

        int n = 5;

        int answer = solution(n);
        System.out.println(answer);
    }
}
