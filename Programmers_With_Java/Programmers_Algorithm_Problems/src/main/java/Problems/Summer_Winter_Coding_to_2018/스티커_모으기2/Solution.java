package Problems.Summer_Winter_Coding_to_2018.스티커_모으기2;

public class Solution {

    int[] stickers;
    int size;
    int[] dp1, dp2;

    void init() {

        size = stickers.length;

        dp1 = new int[size];
        dp2 = new int[size];

        dp1[0] = 0;
        dp1[1] = stickers[1];
        dp2[0] = stickers[0];
        dp2[1] = Math.max(stickers[0], stickers[1]);
    }

    int calculateDP() {

        for (int i = 2; i < size; i++) {
            dp1[i] = Math.max(dp1[i - 1], dp1[i - 2] + stickers[i]);
            dp2[i] = Math.max(dp2[i - 1], dp2[i - 2] + stickers[i]);
        }

        return Math.max(dp1[size - 1], dp2[size - 2]);
    }


    public int solution(int sticker[]) {

        // dp를 사용한다.
        // 기본적으로는 dp[i] = max(dp[i - 1] + sticker[i], dp[i - 2]) 이다.
        // 하지만 첫 번째 스티커의 상태가 마지막 스티커의 상태에 영향을 미친다.
        // 때문에 첫 번째 스티커를 뗐을 때와 안 뗐을 때를 구분해서 2번 진행한다.

        if (sticker.length == 1)
            return sticker[0];

        int answer = 0;

        stickers = sticker;

        init();

        answer = calculateDP();

        return answer;
    }

    public void service() {

        int[] stickers = {14, 6, 5, 11, 3, 9, 2, 10};

        int answer = solution(stickers);
        System.out.println(answer);
    }
}
