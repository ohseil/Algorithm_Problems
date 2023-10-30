package Problems._2022_KAKAO_TECH_INTERNSHIP.등산코스_정하기;

import java.util.*;

/**
 * 기본적인 아이디어는 최저 intensity의 경로를 이용해야 한다면,
 * 출발지 -> 산봉우리 경로와 산봉우리 -> 출발지 경로를 같은 경로를 이용해도 조건을 만족한다는 것이다.
 * 이 아이디어를 기반으로 하면 결국,
 * 모든 출발지에서 모든 산봉우리까지의 경로 중 가장 낮은 intensity의 경로를 구하면 된다.
 *
 * 이 풀이에서는 산봉우리를 출발지로 해서 BFS를 수행했다. ( 출발지를 BFS의 출발지로 정해도 상관없다. )
 * BFS를 수행하는 과정에서 다음 지역으로 이동하기 위한 조건은,
 * 1. 산봉우리가 아니어야 한다.
 * 2. 이동했을 때 기존에 탐색 되었던 경로보다 intensity가 낮아야 한다.
 * 이런 조건으로 미리 안 될 경로들을 쳐냄으로써 시간복잡도를 낮췄다.
 * 또한 모든 산봉우리를 출발지로 한 번에 큐에 넣어서 시작하지 않고,
 * summits 배열을 정렬 후에 하나씩 출발지로 선정해서 탐색함으로써
 * 가장 낮은 intensity의 경로가 여러 개일 때 낮은 산봉우리 번호가 우선이어야 한다는 조건을 만족시켰다.
 *
 */

public class Solution {

    private static final int MAX_COST = 10000001;

    private Map<Integer, List<Edge>> costMap;
    private int[] gateMap;
    private int[] summitMap;

    public void service() {
        int n = 6;
        int[][] paths = new int[][]{{1,2,3},{2,3,5},{2,4,2},{2,5,4},{4,5,3},{4,6,1},{5,6,1}};
        int[] gates = {1,3};
        int[] summits = {5};

        int[] answer = solution(n, paths, gates, summits);
        System.out.println(answer[0] + " " + answer[1]);
    }

    public int[] solution(int n, int[][] paths, int[] gates, int[] summits) {
        int[] answer = {};

        costMap = new HashMap<>();
        gateMap = new int[n + 1];
        summitMap = new int[n + 1];

        makeMaps(paths, gates, summits);
        answer = findMinIntensity(n, summits);
        return answer;
    }

    private void makeMaps(final int[][] paths, final int[] gates, final int[] summits) {
        for (int[] path : paths) {
            List<Edge> list = costMap.getOrDefault(path[0], new ArrayList<>());
            list.add(new Edge(path[1], path[2]));
            costMap.put(path[0], list);

            list = costMap.getOrDefault(path[1], new ArrayList<>());
            list.add(new Edge(path[0], path[2]));
            costMap.put(path[1], list);
        }
        for (int gate : gates) {
            gateMap[gate] = 1;
        }
        for (int summit : summits) {
            summitMap[summit] = 1;
        }
    }

    private int[] findMinIntensity(final int n, final int[] summits) {
        int[] minIntensityData = new int[]{0, MAX_COST};
        int[] visited = new int[n + 1];
        Queue<Node> q = new LinkedList<>();

        for (int i = 1; i <= n; i++) {
            visited[i] = MAX_COST;
        }

        Arrays.sort(summits);

        for (int summit : summits) {
            q.add(new Node(summit, 0));

            while (!q.isEmpty()) {
                Node node = q.poll();

                if (gateMap[node.num] == 1) {
                    if (node.maxCost < minIntensityData[1]) {
                        minIntensityData[0] = summit;
                        minIntensityData[1] = node.maxCost;
                    }
                }

                for (Edge edge : costMap.get(node.num)) {
                    if (summitMap[edge.to] == 1) {
                        continue;
                    }

                    int maxCost = Math.max(node.maxCost, edge.cost);

                    if (maxCost >= visited[edge.to]) {
                        continue;
                    }

                    q.add(node.makeNextNode(edge.to, maxCost));
                    visited[edge.to] = maxCost;
                }
            }
        }
        return minIntensityData;
    }

    static class Edge {
        int to;
        int cost;

        public Edge(int to, int cost) {
            this.to = to;
            this.cost = cost;
        }
    }

    static class Node {
        int num;
        int maxCost;

        public Node(int num, int maxCost) {
            this.num = num;
            this.maxCost = maxCost;
        }

        public Node makeNextNode(int num, int maxCost) {
            return new Node(num, maxCost);
        }
    }
}
