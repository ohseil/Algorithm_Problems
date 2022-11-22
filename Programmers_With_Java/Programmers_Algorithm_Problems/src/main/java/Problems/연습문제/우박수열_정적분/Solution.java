package Problems.연습문제.우박수열_정적분;

import java.util.ArrayList;
import java.util.List;

import static java.lang.Math.abs;

public class Solution {

    private class Pos {

        final int x;
        final int y;

        Pos(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    private List<Double> definiteIntegralAreas = new ArrayList<>();
    private List<Double> answers = new ArrayList<>();

    private double calculateAreaInRange(final Pos smallYPos, final Pos bigYPos) {

        final double xDif = abs(bigYPos.x - smallYPos.x);
        final double yDif = bigYPos.y - smallYPos.y;

        return (xDif * smallYPos.y) + (xDif * yDif / 2);
    }

    private void findDefiniteIntegralsInHailstormSequence(int num) {

        int x = 1;

        while (num != 1) {

            int nextNum;
            int nextX = x + 1;

            double area;

            if (num % 2 == 0) {
                nextNum = num / 2;
                area = calculateAreaInRange(new Pos(x, num), new Pos(nextX, nextNum));
            }
            else {
                nextNum = num * 3 + 1;
                area = calculateAreaInRange(new Pos(nextX, nextNum), new Pos(x, num));
            }

            definiteIntegralAreas.add(area);

            num = nextNum;
            x = nextX;
        }
    }

    private double findAreaInRange(final int start, final int end) {

        double totalArea = 0;

        for (int i = start; i <= end; i++)
            totalArea += definiteIntegralAreas.get(i);

        return totalArea;
    }

    public double[] solution(int k, int[][] ranges) {

        // 우박 수열을 계산하면서 각 x마다
        // x ~ x+1 범위의 정적분 영역을 계산해서 배열에 저장한다.
        // 각 입력 범위마다 저장된 영역의 배열을 확인해서 넓이들을 더해서 계산한다.

        double[] answer = {};

        findDefiniteIntegralsInHailstormSequence(k);

        for (int[] range : ranges) {

            int start = range[0];
            int end = definiteIntegralAreas.size() + range[1];

            if (start == end) {
                answers.add(0.0);
                continue;
            }

            if (start > end) {
                answers.add(-1.0);
                continue;
            }

            // 저장된 각 영역의 넓이는 범위의 작은 x값을 기준으로 저장되어 있기 때문에
            // 조건 확인 후 마지막 범위의 작은 x값으로 변경해 준다.
            end--;

            answers.add(findAreaInRange(start, end));
        }

        answer = new double[answers.size()];
        for (int i = 0; i < answer.length; i++)
            answer[i] = answers.get(i);

        return answer;
    }

    public void service() {

        int k = 5;
        int[][] ranges = {{0,0},{0,-1},{2,-3},{3,-3}};

        double[] answer = solution(k, ranges);
        for (double a : answer)
            System.out.print(a + " ");
    }
}
