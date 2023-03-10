package Problems.연습문제.유사_칸토어_비트열;

public class Solution {

    long[] totalNumInLayers;
    long[] oneNumInLayers;

    public void service() {
        final int n = 2;
        final long l = 4;
        final long r = 17;

        final int answer = solution(n, l, r);
        System.out.println(answer);
    }

    public int solution(int n, long l, long r) {
        int answer = 0;

        setUp();

        final int lNum = countOneNum(n, l - 1);
        final int rNum = countOneNum(n, r);

        answer = rNum - lNum;
        return answer;
    }

    private void setUp() {
        totalNumInLayers = new long[21];
        oneNumInLayers = new long[21];

        totalNumInLayers[0] = 1;
        oneNumInLayers[0] = 1;

        for (int layer = 1; layer <= 20; layer++) {
            totalNumInLayers[layer] = totalNumInLayers[layer - 1] * 5;
            oneNumInLayers[layer] = oneNumInLayers[layer - 1] * 4;
        }
    }

    private int countOneNum(final int layer, long toPos) {
        int num = 0;

        for (int i = layer - 1; i >= 0; i--) {
            long quotient = toPos / totalNumInLayers[i];
            long rest = toPos % totalNumInLayers[i];

            if (quotient > 2) {
                num += oneNumInLayers[i] * (quotient - 1);
            } else if (quotient == 2) {
                num += oneNumInLayers[i] * quotient;
                rest = 0;
            } else {
                num += oneNumInLayers[i] * quotient;
            }

            if (rest == 0) {
                break;
            }

            toPos = rest;
        }
        return num;
    }
}
