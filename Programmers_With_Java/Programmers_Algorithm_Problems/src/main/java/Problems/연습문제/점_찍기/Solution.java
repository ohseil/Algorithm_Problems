package Problems.연습문제.점_찍기;

public class Solution {

    private long[] coordinateList;

    private void init(final int k, final int d) {

        coordinateList = new long[d / k + 1];

        for (int i = 0; i <= (d / k); i++) {
            coordinateList[i] = (long)k * i;
        }

    }

    private double findDist(final long x, final long y) {
        return Math.sqrt(x * x + y * y);
    }

    private long findNumOfYsCanMakeMaxDistOrLessUsingX(final long x, final int MAX_DIST) {

        int numOfYs;

        int start = 0;
        int end = coordinateList.length - 1;
        int mid;

        long maxY = 0;
        int maxYIdx = 0;

        while (start <= end) {

            mid = (start + end) / 2;

            long y = coordinateList[mid];

            if (findDist(x, y) <= MAX_DIST) {

                if (y > maxY) {
                    maxY = y;
                    maxYIdx = mid;
                }

                start = mid + 1;

            }
            else
                end = mid - 1;

        }

        numOfYs = maxYIdx + 1;

        return numOfYs;
    }


    public long solution(int k, int d) {

        /*

            이진 탐색을 사용했다.

            가능한 x와 y의 값의 범위는 둘 다 같다.
            0, k, 2*k, 3*k ... (d이하의 최대 n*k) 가 된다.

            결국 이 범위의 값들 중 2개를 선택하는 모든 경우를 확인해 보면 된다.
            하지만 범위의 최대 크기가 크기 때문에
            2중 for문으로는 시간이 너무 오래 걸린다.

            따라서 x를 기준으로 가능한 모든 y의 개수를 구하는데,
            구하는 방법으로 이진 탐색을 사용했다.

            원점으로부터의 거리는 루트(x*x + y*y) 이다.
            이 거리가 d 이하인 y중 가장 큰 값의 index를 이진 탐색을 통해 찾는다.

            그러면 해당 값보다 작은 값들까지 조건에 맞는 y라는 것을 알 수 있다.

         */

        long answer = 0;

        init(k, d);

        for (long x : coordinateList)
            answer += findNumOfYsCanMakeMaxDistOrLessUsingX(x, d);

        return answer;
    }

    public void service() {

        int k = 2;
        int d = 4;

        long answer = solution(k, d);
        System.out.println(answer);
    }
}
