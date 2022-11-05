package Problems.Summer_Winter_Coding_to_2018.배달;

import java.util.PriorityQueue;
import java.util.Queue;

public class Solution {

    private final int INF = 20000000;

    int[][] roadMap;
    int[] minNeedTimesOfRoutes;

    class RoadInform implements Comparable<RoadInform> {
        int needTime;
        int country;

        RoadInform(int needTime, int country) {
            this.needTime = needTime;
            this.country = country;
        }

        @Override
        public int compareTo(RoadInform o) {
            if (this.needTime < o.needTime) return -1;
            else return 1;
        }
    }

    void makeRoadMap(int n, int[][] roads) {

        roadMap = new int[n + 1][n + 1];

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                roadMap[i][j] = 0;
            }
        }

        for (int[] road : roads) {

            int a = road[0];
            int b = road[1];
            int needTime = road[2];

            if (needTime < roadMap[a][b]
                || roadMap[a][b] == 0) {
                roadMap[a][b] = roadMap[b][a] = needTime;
            }
        }
    }

    void initMinNeedTimesOfRoutes(int n) {
        minNeedTimesOfRoutes = new int[n + 1];
        for (int i = 1; i <= n; i++)
            minNeedTimesOfRoutes[i] = INF;
    }

    void findMinNeedTimeOfAllRoute(int n) {

        Queue<RoadInform> pq = new PriorityQueue();

        pq.add(new RoadInform(0, 1));

        while (pq.isEmpty() == false) {

            RoadInform roadInform = pq.poll();

            if (minNeedTimesOfRoutes[roadInform.country] != INF)
                continue;

            minNeedTimesOfRoutes[roadInform.country] = roadInform.needTime;

            for (int next = 1; next <= n; next++) {

                int needTime = roadMap[roadInform.country][next];

                if (needTime > 0) {
                    pq.add(new RoadInform(roadInform.needTime + needTime, next));
                }
            }
        }
    }

    int getCanDeliverCountryCount(int n, int limitTime) {

        int canDeliverCountryCount = 0;

        for (int i = 1; i <= n; i++) {

            int needTime = minNeedTimesOfRoutes[i];

            if (needTime <= limitTime)
                canDeliverCountryCount++;
        }

        return canDeliverCountryCount;
    }

    public int solution(int N, int[][] road, int K) {

        // 다익스트라 알고리즘을 이용해서
        // 1번 마을부터 모든 마을까지의 최단 시간을 구한다.

        // 그리고 K 이하의 시간이 걸리는 마을의 개수를 센다.

        // 다익스트라 이전에 road 배열을 참조해서
        // 마을 간의 경로 정보를 hash map에 저장해서 사용한다.
        // 이 때, 두 마을 사이에 여러 개의 경로 정보가 있을 수 있다.
        // 여러 경로들 중에 가장 적게 걸리는 시간만 저장한다.

        int answer = 0;

        makeRoadMap(N, road);
        initMinNeedTimesOfRoutes(N);
        findMinNeedTimeOfAllRoute(N);

        answer = getCanDeliverCountryCount(N, K);

        return answer;
    }

    public void service() {

        int n = 5;
        int[][] roads = {{1,2,1},{2,3,3},{5,2,2},{1,4,2},{5,3,1},{5,4,2}};
        int k = 3;

        int answer = solution(n, roads, k);
        System.out.println(answer);
    }

}
