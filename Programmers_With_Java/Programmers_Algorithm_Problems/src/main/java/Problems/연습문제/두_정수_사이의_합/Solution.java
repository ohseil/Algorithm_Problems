package Problems.연습문제.두_정수_사이의_합;

/*

    간단한 방법으로는 범위에 포함하는 숫자들을 모두 더하면 된다.

    더 효율적인 방법으로는,
    1 ~ n 까지의 합을 구하는 공식을 이용하는 것이다.

    min값이 0보다 크다면, (1 ~ max까지의 합) - (1 ~ min-1까지의 합)이고
    min값이 0보다 작다면, (1 ~ max까지의 합) + (-1 ~ min까지의 합)이다.

    min 부분의 공식을 구해보면, (min-1) * min / 2, min * (min-1) / 2
    같은 공식이 나온다.
    따라서 min값이 양수이건 음수이건 상관 없이,
    답은 max * (max + 1) / 2 - (min-1) * min / 2가 된다.

 */

public class Solution {

    private long maxNum;
    private long minNum;

    public void service() {

        int a = 3;
        int b = 5;

        long answer = solution(a, b);
        System.out.println(answer);

    }

    public long solution(int a, int b) {

        long answer = 0;

        maxNum = Math.max(a, b);
        minNum = Math.min(a, b);

        answer = (maxNum * (maxNum + 1) / 2) - ((minNum - 1) * minNum / 2);

        return answer;
    }

}
