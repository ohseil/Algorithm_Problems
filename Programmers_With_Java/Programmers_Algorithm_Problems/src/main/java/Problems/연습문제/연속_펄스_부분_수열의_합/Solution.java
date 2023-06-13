package Problems.연습문제.연속_펄스_부분_수열의_합;

/**
 * 특정 연속 부분수열에 대한 연속 펄스 부분수열은 2가지 경우 뿐이다.
 * 첫 번째 원소에 곱할 펄스 수열의 숫자가 1부터 시작하거나 -1부터 시작하는 경우로 나뉜다.
 * 두 가지 경우에서 최대 부분 수열을 구한다.
 *
 * 최대 부분 수열을 구하는 방법은 다음과 같다.
 * 첫 번째 원소부터 탐색해 나가면서 값을 더해나간다. 더해 나가면서 최대 값인지 계속 확인한다. 이 때 더한 값을 sum이라고 하자.
 * 현재 탐색중인 숫자까지 더한 값이 음수가 아니라면 이 다음에 오는 숫자들과 무조건 합치는게 최대 부분 수열이 되는 방향이다.
 * 현재 탐색중인 숫자까지 더한 값이 음수가 된다면, 이후에 오는 숫자들과 합치지 않는게 최대 부분 수열이 되는 방향이다.
 * 따라서 음수라면 sum을 0으로 초기화 하고, 이 다음 숫자부터 다시 더해나간다.
 */

public class Solution {

    public void service() {
        final int[] sequence = {2, 3, -6, 1, 3, -1, 2, 4};

        final long answer = solution(sequence);
        System.out.println(answer);
    }

    public long solution(final int[] sequence) {
        long answer = 0;
        long sum1 = 0;
        long sum2 = 0;

        for (int i = 0; i < sequence.length; i++) {
            long num1 = 0;
            long num2 = 0;

            if (i % 2 == 0) {
                num1 = sequence[i] * 1;
                num2 = sequence[i] * (-1);
            } else {
                num1 = sequence[i] * (-1);
                num2 = sequence[i] * 1;
            }

            if (sum1 + num1 < 0) {
                sum1 = 0;
            } else {
                sum1 += num1;
            }
            if (sum2 + num2 < 0) {
                sum2 = 0;
            } else {
                sum2 += num2;
            }

            if (sum1 > answer) {
                answer = sum1;
            }
            if (sum2 > answer) {
                answer = sum2;
            }
        }

        return answer;
    }
}
