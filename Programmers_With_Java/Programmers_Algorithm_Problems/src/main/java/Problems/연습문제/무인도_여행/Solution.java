package Problems.연습문제.무인도_여행;

import java.util.*;

/**
 * 각 섬마다 BFS 사용해서 음식 개수 세기
 */

public class Solution {

    private final int[] dr = {1,-1,0,0};
    private final int[] dc = {0,0,1,-1};

    private int maxR;
    private int maxC;
    private List<Integer> foods;

    private int[][] visitedMap;

    public void service() {
        final String[] maps = {"X591X","X1X5X","X231X", "1XXX1"};

        final int[] answer = solution(maps);
        for (int a : answer) {
            System.out.print(a + " ");
        }
        System.out.println();
    }

    public int[] solution(final String[] maps) {
        int[] answer = {};

        setUp(maps);

        for (int r = 0; r < maxR; r++) {
            for (int c = 0; c < maxC; c++) {
                if (maps[r].charAt(c) == 'X' || visitedMap[r][c] == 1) {
                    continue;
                }

                findFootCnt(r, c, maps);
            }
        }

        if (foods.isEmpty()) {
            answer = new int[]{-1};
        } else {
            answer = foods.stream()
                    .mapToInt(Integer::intValue)
                    .sorted()
                    .toArray();
        }
        return answer;
    }

    private void setUp(final String[] maps) {
        maxR = maps.length;
        maxC = maps[0].length();
        foods = new ArrayList<>();
        visitedMap = new int[maxR][maxC];
    }

    private void findFootCnt(final int startR, final int startC, final String[] maps) {
        int foodCnt = Integer.parseInt(String.valueOf(maps[startR].charAt(startC)));
        visitedMap[startR][startC] = 1;

        Queue<Pos> queue = new LinkedList<>();
        queue.add(new Pos(startR, startC));

        while (!queue.isEmpty()) {
            Pos cur = queue.poll();

            for (int d = 0; d < 4; d++) {
                int nr = cur.r + dr[d];
                int nc = cur.c + dc[d];

                if (!isMap(nr, nc)
                        || (maps[nr].charAt(nc) == 'X')
                        || (visitedMap[nr][nc] == 1)) {
                    continue;
                }

                foodCnt += Integer.parseInt(String.valueOf(maps[nr].charAt(nc)));
                queue.add(new Pos(nr, nc));
                visitedMap[nr][nc] = 1;
            }
        }

        foods.add(foodCnt);
    }

    private boolean isMap(final int r, final int c) {
        return 0 <= r && r < maxR && 0 <= c && c < maxC;
    }

    static class Pos {
        final int r;
        final int c;

        Pos(final int r, final int c) {
            this.r = r;
            this.c = c;
        }
    }
}
