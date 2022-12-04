package Problems.연습문제.부대복귀;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;

public class Solution {

    private final int MAX_COST  = 500001;
    private final int COST_PER_ROAD = 1;

    private Map<Integer, Map<Integer, Integer>> roadMap;
    private int[] shortestDistFromDestinationList;

    private void init(final int n) {

        roadMap = new HashMap<>();
        shortestDistFromDestinationList = new int[n + 1];

        for (int i = 1; i <= n; i++)
            shortestDistFromDestinationList[i] = MAX_COST;

    }

    private void makeRoadMap(final int[][] roads) {

        for (int[] road : roads) {

            int a = road[0];
            int b = road[1];

            Map<Integer, Integer> fromARoadMap = roadMap.getOrDefault(a, new HashMap<>());
            Map<Integer, Integer> fromBRoadMap = roadMap.getOrDefault(b, new HashMap<>());

            fromARoadMap.put(b, 1);
            fromBRoadMap.put(a, 1);
            roadMap.put(a, fromARoadMap);
            roadMap.put(b, fromBRoadMap);

        }

    }

    private void findShortestDistFromDestinationToAllRegion(final int destination) {

        // 목적지부터 BFS.
        shortestDistFromDestinationList[destination] = 0;

        Queue<Integer> queue = new LinkedList<>();
        queue.add(destination);

        while (queue.isEmpty() == false) {

            int regionNum = queue.poll();

            for (int nextRegionNum : roadMap.get(regionNum).keySet()) {

                int distToRegion = shortestDistFromDestinationList[regionNum];
                int distToNextRegion = shortestDistFromDestinationList[nextRegionNum];

                if (distToRegion + COST_PER_ROAD >= distToNextRegion)
                    continue;

                shortestDistFromDestinationList[nextRegionNum] = distToRegion + COST_PER_ROAD;
                queue.add(nextRegionNum);

            }
        }

    }

    public int[] solution(int n, int[][] roads, int[] sources, int destination) {

        /*

        목적지를 출발점으로 해서 모든 지역까지 최단 거리를 BFS로 구한다.
        만약 길을 통과하는데 걸리는 시간이 고정되어 있지 않았다면,
        다익스트라 알고리즘을 사용했을 것이다.
        하지만 걸리는 시간이 고정되어 있기 때문에,
        BFS만 사용해도 모든 지역까지의 최단 거리를 구할 수 있다.

         */

        int[] answer = new int[sources.length];

        init(n);
        makeRoadMap(roads);
        findShortestDistFromDestinationToAllRegion(destination);

        for (int i = 0; i < sources.length; i++) {

            int memberPos = sources[i];
            int shortestDist = shortestDistFromDestinationList[memberPos];

            answer[i] = (shortestDist < MAX_COST) ? shortestDist : -1;

        }

        return answer;
    }

    public void service() {

        int n = 3;
        int[][] roads = {{1,2},{2,3}};
        int[] sources = {2,3};
        int destination = 1;

        int[] answer = solution(n, roads, sources, destination);

        for (int a : answer)
            System.out.print(a + " ");
        System.out.println();

    }
}
