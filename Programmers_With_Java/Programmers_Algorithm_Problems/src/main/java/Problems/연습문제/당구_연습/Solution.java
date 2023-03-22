package Problems.연습문제.당구_연습;

/*

    수학 공식을 알아야 풀 수 있는 문제다.
    당구대 4개의 면 중 왼쪽 면을 기준으로 설명해 보면,
    공 2개 중에 하나를 면을 기준으로 대칭이 되도록 이동시킨다.
    이동시킨 공과 나머지 공의 거리가 최소 거리다.

    4개의 면을 기준으로 최소 거리를 모두 구해서 최소 값을 구한다.
    이 때, 주의해야 할 점은 공 2개가 면과 수직선 경로에 위치한다면,
    면과 가까운 공이 내가 쳐야할 공이 아니라면 면에 닿기 전에 공을 맞추기 때문에 원 쿠션이 불가능하다.

    당구대의 꼭지점은 신경 쓸 필요가 없다. 함정이다.
    이유는 위의 공식대로 생각해 보면, 꼭지점과 공 2개가 직선 경로에 있을 때 최소 거리는
    꼭지점 기준으로 대칭이 되도록 이동시켜서 구해야 한다.
    그런데, 꼭지점 기준으로 이동을 시키면 x와 y 둘 다 이동시켜야 하는데
    그냥 꼭지점 근처 아무 면이나 선택해서 기준으로 잡으면 x나 y만 이동시키면 되기 때문에
    무조건 더 짧은 거리가 된다.

 */

public class Solution {

    private int maxX;
    private int maxY;

    public void service() {
        final int m = 10;
        final int n = 10;
        final int startX = 3;
        final int startY = 7;
        final int[][] balls = {{7,7},{2,7},{7,3}};

        final int[] answer = solution(m, n, startX, startY, balls);
        for (int a : answer) {
            System.out.print(a + " ");
        }
        System.out.println();
    }

    public int[] solution(final int m, final int n, final int startX, final int startY, final int[][] balls) {
        int[] answer = new int[balls.length];
        maxX = m;
        maxY = n;

        for (int i = 0; i < balls.length; i++) {
            answer[i] = findMinDistInSide(startX, startY, balls[i][0], balls[i][1]);
        }
        return answer;
    }

    private int findMinDistInSide(final int startX, final int startY, final int ballX, final int ballY) {
        int minDist = Integer.MAX_VALUE;

        if (!(startY == ballY && startX > ballX)) {
            minDist = Math.min(minDist, makeDist(-startX, startY, ballX, ballY));
        }
        if (!(startY == ballY && startX < ballX)) {
            minDist = Math.min(minDist, makeDist(maxX + (maxX - startX), startY, ballX, ballY));
        }
        if (!(startX == ballX && startY > ballY)) {
            minDist = Math.min(minDist, makeDist(startX, -startY, ballX, ballY));
        }
        if (!(startX == ballX && startY < ballY)) {
            minDist = Math.min(minDist, makeDist(startX, maxY + (maxY - startY), ballX, ballY));
        }
        return minDist;
    }

    private int makeDist(final int x1, final int y1, final int x2, final int y2) {
        return (int) (Math.pow(Math.abs(x1 - x2), 2) + Math.pow(Math.abs(y1 - y2), 2));
    }
}
