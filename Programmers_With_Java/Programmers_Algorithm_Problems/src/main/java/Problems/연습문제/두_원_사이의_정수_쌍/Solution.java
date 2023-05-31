package Problems.연습문제.두_원_사이의_정수_쌍;

/**
 * 2차원 직교 좌표계에서 4개의 구간은 모두 같은 모양이다.
 * x와 y가 양수일 때의 범위만 구하면, 나머지 3개의 구간은 알 수 있다.
 * 각 x값을 기준으로 원 2개의 y값을 구한다.
 * 원의 공식은 x^2 + y^2 = r^2 이고, y^2 = r^2 - x^2 이다.
 *
 * y2 - y1 + 1이 해당 x값에 대해 x축과 수직인 선에서 두 원 사이에 포함 된 점의 개수다.
 * x = 0 부터 x = r2까지의 계산 된 값을 모두 더한다.
 * 이 때, 주의해야 할 점은 이렇게 구한 값에 4개의 구간만큼 곱하면 각 x = 0인 선과 y = 0인 선이 겹치게 된다.
 * 따라서 이 풀이에서는 이 라인을 모두 빼고 계산 후에 해당 라인들에 포함 된 점의 개수를 더해주는 방향으로 계산했다.
 */

public class Solution {

    long r1;
    long r2;

    public void service() {
        final int r1 = 2;
        final int r2 = 3;

        final long answer = solution(r1, r2);
        System.out.println(answer);
    }

    public long solution(final int r1, final int r2) {
        long answer = 0;
        long line;

        this.r1 = r1;
        this.r2 = r2;

        for (int x = 1; x <= r1 - 1; x++) {
            answer += (findY2(x) - findY1(x) + 1);
        }
        for (int x = r1; x <= r2 - 1; x++) {
            answer += (findY2(x));
        }

        line = r2 - r1 + 1;

        answer = (answer * 4) + (line * 4);

        return answer;
    }

    private long findY1(final long x) {
        return (long) Math.ceil(Math.sqrt((r1 * r1) - (x * x)));
    }
    private long findY2(final long x) {
        return (long) Math.floor(Math.sqrt((r2 * r2) - (x * x)));
    }
}
