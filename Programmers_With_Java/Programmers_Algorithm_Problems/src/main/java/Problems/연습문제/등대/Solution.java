package Problems.연습문제.등대;

import java.util.*;

public class Solution {

    private Map<Integer, List<Integer>> routeMap = new HashMap<>();
    private Map<Integer, List<Integer>> tree = new HashMap<>();
    private Set<Integer> validations = new HashSet<>();

    private int theNumberOfTurnedOnLighthouse = 0;

    private void makeRouteMap(int[][] lighthouse) {

        for (int[] route : lighthouse) {
            if (routeMap.get(route[0]) == null) routeMap.put(route[0], new ArrayList<>());
            if (routeMap.get(route[1]) == null) routeMap.put(route[1], new ArrayList<>());
            routeMap.get(route[0]).add(route[1]);
            routeMap.get(route[1]).add(route[0]);
        }
    }

    private int findRouteNode() {

        int routeNode = 1;

        for (int nodeInRoute : routeMap.keySet()) {
            if (routeMap.get(nodeInRoute).size() > 1) {
                routeNode = nodeInRoute;
                break;
            }
        }

        return routeNode;
    }

    private void makeTree(int n, int routeNode) {

        Queue<Integer> q = new LinkedList<>();
        Set<Integer> visitedNodeSet = new HashSet<>();

        for (int i = 1; i <= n; i++)
            tree.put(i, new ArrayList<>());

        q.add(routeNode);
        visitedNodeSet.add(routeNode);

        while (q.isEmpty() == false) {

            int parent = q.poll();

            for (Integer child : routeMap.get(parent)) {

                if (visitedNodeSet.contains(child) == true)
                    continue;

                tree.get(parent).add(child);

                q.add(child);
                visitedNodeSet.add(child);
            }

        }

    }

    private void countTheMinNumberOfTurnedOnLighthouse(int parent) {

        if (tree.get(parent).isEmpty() == true)
            return;

        boolean isTurnOn = false;

        for (int child : tree.get(parent)) {

            countTheMinNumberOfTurnedOnLighthouse(child);

            if (validations.contains(child) == false) isTurnOn = true;
        }

        if (isTurnOn == true) {
            validations.add(parent);
            theNumberOfTurnedOnLighthouse++;
        }
    }

    public int solution(int n, int[][] lighthouse) {

        // 기본 생각은 가장 끝에 연결되어 있는 등대를 봤을 때,
        // 해당 노드와 연결 된 등대 중 하나를 밝혀야 한다.
        // 그렇다면 무조건 연결 된 등대를 밝히는 것이 좋다.
        // 연결 된 등대는 2개의 등대와 연결되어 있기 때문이다.
        // 둘 중 하나를 무조건 밝혀야 한다면 연결 된 등대를 무조건 밝혀야 한다.

        // 이 생각으로부터 해결 방법을 생각했다.
        // 등대끼리 연결 된 뱃길은 n-1개이기 때문에 트리 구조로 볼 수 있다.
        // 그렇다면, 2개 이상의 등대와 연결 된 노드를 루트 노드로 해서 트리를 만들 수 있다.
        // 트리로 만들면 위에서 생각했던 시작 노드는 리프 노드들이 된다.

        // 리프 노드들을 시작 노드로 해서
        // 각 리프 노드와 연결 된 등대를 밝히고, 다음 연결 된 등대는 밝히지 않는 식으로 진행한다.
        // 그리고 각 서브 트리를 보면 서브 트리의 루트 노드는 2개 이상의 등대와 연결 된 등대다.
        // 이 등대는 위의 방식대로 밝혀오면, 어느 경로 기준에서는 밝히지 않는 등대가 되고
        // 어느 경로 기준에서는 밝히는 등대가 된다.
        // 연결 된 자식 노드의 등대들의 계산이 끝났을 때,
        // 모든 자식 등대들이 밝혀져 있다면 서브 트리의 루트 노드 등대는 밝히지 않는다.
        // 하지만 하나라도 밝혀져 있지 않은 자식 등대가 있다면 서브 트리의 루트 노드 등대를 밝혀야 한다.

        // 여기서 들 수 있는 생각은 밝혀져 있지 않은 자식 노드가 있어도 그냥 넘어가고
        // 다음 노드에서 불을 밝히면 되지 않나? 라고 생각이 든다.
        // 그리고 이 방법 말고 여러 개의 등대와 연결 되어있는 등대를 우선으로 밝히고
        // 이 등대를 기준으로 자식 노드들을 밝혀가는 방법이 더 적은 수의 등대를 밝힐 수 있는 방법이 아닐까? 라는 생각도 든다.
        // 하지만 생각을 해보면, 기존 방법으로 계산한 상황에서 서브 트리의 루트 노드가 밝혀져 있지 않은 상황일 때,
        // 이 서브 트리를 거꾸로 루트 노드를 밝히고 자식 등대를 계산해 나가면 밝혀질 노드의 수는 더 많아진다.
        // 왜냐하면 이렇게 계산하면 결국 리프 노드를 밝히게 된다. 그런데 앞에서 말했듯이 리프 노드보다 무조건 연결 된 등대를 밝히는 것이
        // 어떤 상황에서도 적은 수의 등대를 밝히는 방법이 된다.
        // 많은 등대와 연결 된 등대부터 밝히는 것이 뭔가 가장 적은 개수로 밝힐 수 있는 방법 같지만,
        // 중요한 것은 가장 끝에 연결 된 등대는 밝히지 말고 연결 된 등대를 밝히는 것이 무조건 좋은 방법이라는 것이다.
        // 이 방법의 반례를 찾아보려 다른 등대를 밝혀보는 방법을 떠올려 봐도 결국 같은 수를 밝히거나 많은 수를 밝히게 된다.

        int answer = 0;
        int routeNode;

        makeRouteMap(lighthouse);
        routeNode = findRouteNode();
        makeTree(n, routeNode);
        countTheMinNumberOfTurnedOnLighthouse(routeNode);

        answer = theNumberOfTurnedOnLighthouse;

        return answer;
    }

    public void service() {

        int n = 8;
        int[][] lighthouse = {{1,2},{1,3},{1,4},{1,5},{5,6},{5,7},{5,8}};

        int answer = solution(n, lighthouse);
        System.out.println(answer);
    }
}
