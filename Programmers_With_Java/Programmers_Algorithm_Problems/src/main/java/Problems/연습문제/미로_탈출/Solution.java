package Problems.연습문제.미로_탈출;

import java.util.LinkedList;
import java.util.Queue;

public class Solution {

    private static final int[] ROW_DIR = {0,0,1,-1};
    private static final int[] COL_DIR = {1,-1,0,0};

    private static final char START = 'S';
    private static final char EXIT = 'E';
    private static final char LEVER = 'L';
    private static final char PASSAGE = 'O';
    private static final char WALL = 'X';

    private int maxR;
    private int maxC;
    private int cost = 0;

    private int[] startPos;
    private int[] exitPos;
    private int[] leverPos;

    public void service() {
        final String[] map = {"SOOOL","XXXXO","OOOOO","OXXXX","OOOOE"};
        final int answer = solution(map);
        System.out.println(answer);
    }

    public int solution(final String[] map) {
        int answer;

        maxR = map.length;
        maxC = map[0].length();

        findNeedPoss(map);
        if (canSearchRoute(map, startPos, leverPos) == false) return -1;
        if (canSearchRoute(map, leverPos, exitPos) == false) return -1;

        answer = cost;
        return answer;
    }

    private void findNeedPoss(final String[] map) {
        for (int r = 0; r < maxR; r++) {
            for (int c = 0; c < maxC; c++) {
                if (map[r].charAt(c) == START) startPos = new int[]{r, c};
                else if (map[r].charAt(c) == EXIT) exitPos = new int[]{r, c};
                else if (map[r].charAt(c) == LEVER) leverPos = new int[]{r, c};
            }
        }
    }

    private boolean canSearchRoute(final String[] map, final int[] start, final int[] end) {
        final Queue<int[]> queue = new LinkedList<>();
        final int[][] visitedMap = new int[maxR][maxC];

        queue.add(new int[]{start[0], start[1], 0});
        visitedMap[start[0]][start[1]] = 1;

        while (queue.isEmpty() == false) {
            int[] pos = queue.poll();

            if (pos[0] == end[0] && pos[1] == end[1]) {
                cost += pos[2];
                return true;
            }

            for (int d = 0; d < 4; d++) {
                int nr = pos[0] + ROW_DIR[d];
                int nc = pos[1] + COL_DIR[d];

                if (isBoardRange(nr, nc) == false) continue;
                if (map[nr].charAt(nc) == WALL) continue;
                if (visitedMap[nr][nc] == 1) continue;

                int[] next = new int[]{nr, nc, pos[2] + 1};
                visitedMap[nr][nc] = 1;
                queue.add(next);
            }
        }

        return false;
    }

    private boolean isBoardRange(final int r, final int c) {
        return 0 <= r && r < maxR && 0 <= c & c < maxC;
    }
}
