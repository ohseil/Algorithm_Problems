package Problems.연습문제.리코쳇_로봇;

import java.util.LinkedList;
import java.util.Queue;

public class Solution {

    private static final int[] dr = {0,0,1,-1};
    private static final int[] dc = {1,-1,0,0};

    private int maxR;
    private int maxC;
    private Pos start;
    private Pos end;

    private final Queue<Pos> queue = new LinkedList<>();
    private final int[][] visitedMap = new int[100][100];

    public void service() {
        final String[] board = {"...D..R", ".D.G...", "....D.D", "D....D.", "..D...."};

        final int answer = solution(board);
        System.out.println(answer);
    }

    public int solution(String[] board) {
        int answer = -1;
        maxR = board.length;
        maxC = board[0].length();

        findStartAndEndPos(board);

        queue.add(start);
        visitedMap[start.r][start.c] = 1;

        while(!queue.isEmpty()) {
            Pos cur = queue.poll();

            if (cur.r == end.r && cur.c == end.c) {
                answer = cur.cost;
                break;
            }

            for (int d = 0; d < 4; d++) {
                int nr = cur.r;
                int nc = cur.c;

                while (isBoard(nr + dr[d], nc + dc[d])
                        && board[nr + dr[d]].charAt(nc + dc[d]) != 'D') {
                    nr += dr[d];
                    nc += dc[d];
                }

                if (visitedMap[nr][nc] == 1) {
                    continue;
                }

                Pos next = new Pos(nr, nc);
                next.cost = cur.cost + 1;
                queue.add(next);
                visitedMap[nr][nc] = 1;
            }
        }
        return answer;
    }

    private void findStartAndEndPos(final String[] board) {
        for (int r = 0; r < maxR; r++) {
            for (int c = 0; c < maxC; c++) {
                if (board[r].charAt(c) == 'R') {
                    start = new Pos(r,c);
                } else if (board[r].charAt(c) == 'G') {
                    end = new Pos(r,c);
                }
            }
        }
    }

    private boolean isBoard(int r, int c) {
        return 0 <= r && r < maxR && 0 <= c && c < maxC;
    }

    static class Pos {

        int r;
        int c;
        int cost = 0;

        Pos(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }
}
