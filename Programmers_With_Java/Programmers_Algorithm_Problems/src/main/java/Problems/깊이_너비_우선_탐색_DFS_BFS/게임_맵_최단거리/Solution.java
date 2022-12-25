package Problems.깊이_너비_우선_탐색_DFS_BFS.게임_맵_최단거리;

import java.util.LinkedList;
import java.util.Queue;

public class Solution {

    private static final int[] dr = {1,-1,0,0};
    private static final int[] dc = {0,0,1,-1};

    private int maxR;
    private int maxC;

    private int[][] validationMap;

    public void service() {

        int[][] maps = {{1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1}};

        int answer = solution(maps);
        System.out.println(answer);

    }

    public int solution(int[][] maps) {

        int answer = 0;

        init(maps);
        answer = findShortestDist(maps);

        return answer;
    }

    private void init(int[][] maps) {
        maxR = maps.length;
        maxC = maps[0].length;
        validationMap = new int[maps.length][maps[0].length];
    }

    private int findShortestDist(int[][] map) {

        int numOfSqure = 0;
        Queue<int[]> queue = new LinkedList<>();

        queue.add(new int[]{0, 0});
        validationMap[0][0] = 1;
        numOfSqure++;

        while (queue.isEmpty() == false) {

            int qsize = queue.size();

            for (int i = 0; i < qsize; i++) {

                int[] pos = queue.poll();

                if (isArriveDestination(pos[0], pos[1]) == true)
                    return numOfSqure;

                for (int d = 0; d < 4; d++) {

                    int nr = pos[0] + dr[d];
                    int nc = pos[1] + dc[d];

                    if (isMapRange(nr, nc) == false) continue;
                    if (map[nr][nc] == 0) continue;
                    if (validationMap[nr][nc] == 1) continue;

                    queue.add(new int[]{nr, nc});
                    validationMap[nr][nc] = 1;

                }

            }

            numOfSqure++;

        }

        return -1;
    }

    private boolean isArriveDestination(int r, int c) {
        return (r == (maxR - 1) && c == (maxC - 1));
    }

    private boolean isMapRange(int r, int c) {
        return 0 <= r && r < maxR && 0 <= c && c < maxC;
    }

}
