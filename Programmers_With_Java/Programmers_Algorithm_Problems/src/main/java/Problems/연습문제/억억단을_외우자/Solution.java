package Problems.연습문제.억억단을_외우자;

import java.util.HashMap;
import java.util.Map;

/*

    1. 1 ~ e 범위의 숫자들의 나타난 횟수를 구한다.
    2. 1 ~ e 까지의 각 숫자를 시작점으로 했을 때의 가장 많이 나타난 숫자를 dp 알고리즘으로 구한다.

    우선 억억단을 통해서 나오는 숫자라는 것은
    2개의 숫자를 곱해서 나온다는 것을 말하고 이것으로 약수와 연관되어 있다는 것을 알 수 있다.
    결국, 약수의 개수만큼 나타난다. a x b로 구할 수 있는 숫자는 b x a로 구한 것과 별개의 횟수다.
    이렇게 구할수도 있지만, 더 빠르게 구할 수 있다.

    그냥 억억단 과정으로 구하는 것이다.
    다만, 곱한 숫자가 최대 값인 e 이하인 것만 구하면 된다.
    그리고 2개의 숫자를 곱하는 경우는 반대의 경우까지 횟수로 포함시키기 때문에 중복을 제거할 수 있다.
    이렇게 되면 1 ~ e까지의 숫자를 기준으로 각 숫자를 x라고 할 때,
    x ~ e/x 를 곱하는 알고리즘을 만들 수 있다.
    1x1, 1x2 ... 1x(e/1)
    2x2, 2x3 ... 2x(e/2)
    3x3, 3x4 ... 3x(e/3)
    이런식으로 계산하면 빠르게 계산할 수 있다.
    각각 곱한 숫자는 나타난 횟수를 +2 해준다. 두 숫자의 순서를 바꾸는 경우도 고려하기 때문이다.

    여기서 한 가지 고려해야할 점은,
    1x1, 2x2 이런 두 숫자가 같은 경우에는 한 번밖에 나타나지 않으므로 +1을 해줘야 한다.

    각 숫자의 나타난 횟수를 구했다면,
    dp 알고리즘을 진행한다.
    dp[n][0] = n ~ e 사이의 숫자들 중 가장 많이 나타난 숫자의 횟수 ( 결국 dp[n][1]이 나타난 횟수 )
    dp[n][1] = n ~ e 사이의 숫자들 중 가장 많이 나타난 숫자이면서 그 중 가장 작은 숫자

    dp[e][0] = 숫자 e가 나타난 횟수
    dp[e][1] = e

    숫자 e-1부터 1까지 dp값을 구한다.
    구하는 공식은 아래와 같다.

    [ dp[n][0] > dp[n+1][0] ]
    dp[n][0] = 숫자 n이 나타난 횟수
    dp[n][1] = n

    [ dp[n][0] == dp[n+1][0] && dp[n][1] < dp[n+1][1] ]
    dp[n][0] = 숫자 n이 나타난 횟수
    dp[n][1] = n

    [ dp[n][0] < dp[n+1][0] ]
    dp[n] = dp[n+1]

    dp를 모두 계산한 후 주어진 시작 숫자들의 dp값을 참조한다.

 */

public class Solution {

    private final static int IDX_TIMES_TO_APPEAR_MAX = 0;
    private final static int IDX_NUM_TO_APPEAR_MAX = 1;
    
    private Map<Integer, Integer> originIdxMap;
    private int[] numOfDigitsList;
    private int[][] numAppearedMaxTimesList;

    public void service() {

        int e = 8;
        int[] starts = {1,3,7};

        int[] answer = solution(e, starts);
        for (int a : answer)
            System.out.print(a + " ");
        System.out.println();

    }

    public int[] solution(int e, int[] starts) {

        int[] answer = new int[starts.length];

        init(e, starts);
        findNumAppearedMaxTimesInAllRange(e);

        for (int i = 0; i < starts.length; i++)
            answer[i] = numAppearedMaxTimesList[starts[i]][1];

        return answer;
    }

    private void init(final int maxNum, final int[] startNumList) {

        originIdxMap = new HashMap<>();
        numOfDigitsList = new int[maxNum + 1];
        numAppearedMaxTimesList = new int[maxNum + 1][2];

        for (int i = 0; i < startNumList.length; i++)
            originIdxMap.put(startNumList[i], i);

        for (int num = 1; num <= maxNum; num++) {

            int limitNum = maxNum / num;

            for (int numToMultiply = num; numToMultiply <= limitNum; numToMultiply++) {
                if (num == numToMultiply) numOfDigitsList[num * numToMultiply] += 1;
                else numOfDigitsList[num * numToMultiply] += 2;
            }

        }

    }

    private void findNumAppearedMaxTimesInAllRange(final int maxNum) {

        numAppearedMaxTimesList[maxNum][IDX_TIMES_TO_APPEAR_MAX] = numOfDigitsList[maxNum];
        numAppearedMaxTimesList[maxNum][IDX_NUM_TO_APPEAR_MAX] = maxNum;

        for (int i = maxNum - 1; i >= 1; i--) {

            if (numOfDigitsList[i] > numAppearedMaxTimesList[i + 1][IDX_TIMES_TO_APPEAR_MAX]
                    || (numOfDigitsList[i] == numAppearedMaxTimesList[i + 1][IDX_TIMES_TO_APPEAR_MAX] && i < numAppearedMaxTimesList[i + 1][IDX_NUM_TO_APPEAR_MAX])) {
                numAppearedMaxTimesList[i][IDX_TIMES_TO_APPEAR_MAX] = numOfDigitsList[i];
                numAppearedMaxTimesList[i][IDX_NUM_TO_APPEAR_MAX] = i;
            }
            else {
                numAppearedMaxTimesList[i] = numAppearedMaxTimesList[i + 1];
            }

        }

    }

}
