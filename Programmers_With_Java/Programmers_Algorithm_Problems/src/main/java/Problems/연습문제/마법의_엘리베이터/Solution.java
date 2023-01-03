package Problems.연습문제.마법의_엘리베이터;

/*

    주어진 층의 각 자릿수를 0으로 만들기 위해서는,
    각 자릿수마다
    -10^n 버튼을 여러 번 눌러서 0으로 만들거나
    +10^n 버튼을 여러 번 눌러서 한 자리수를 올려서 0으로 만들어야 한다.

    1의 자리부터 계산해서 마지막 자리의 숫자까지 계산한다.
    그러면 각 자릿수마다 2가지 경우가 존재하고,
    모든 경우를 구하면 2^n 가지의 경우가 나온다.
    이 모든 경우를 계산해서 최소 횟수를 구한다.

 */

public class Solution {

    private int minPressCount = 100000000;

    public void service() {

        int storey = 16;

        int answer = solution(storey);
        System.out.println(answer);

    }

    public int solution(int storey) {

        int answer = 0;

        pressBtn(storey, 0);
        answer = minPressCount;

        return answer;
    }

    private void pressBtn(int storey, int pressCount) {

        if (storey == 0) {
            minPressCount = Math.min(pressCount, minPressCount);
            return;
        }

        if (storey == 1) {
            minPressCount = Math.min(pressCount + 1, minPressCount);
            return;
        }

        pressBtn(storey / 10 + 1, pressCount + (10 - storey % 10));
        pressBtn(storey / 10, pressCount + (storey % 10));

    }

}
