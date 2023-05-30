package Problems.연습문제.요격_시스템;

import java.util.*;

/**
 * 풀이 아이디어는 미사일은 무조건 요격되어야 하기 때문에 한 번에 최대한 많이 요격시키면 최소한의 요격 횟수로 요격할 수 있을거라는 생각이다.
 * 작은 x지점부터 큰 x지점까지 차례대로 확인하면서 시작되는 미사일의 개수를 세어나간다.
 * 특정 x지점에서 끝나는 미사일이 하나라도 있다면 요격 미사일을 발사해서 세었던 미사일들을 모두 요격하고, 다음 지점부터 이전 과정을 반복한다.
 *
 * 계산 전에 필요한 데이터를 구성한다.
 * 각 x지점에서 필요한 데이터는 해당 지점에서 시작되는 미사일들의 끝나는 시각 리스트와 해당 지점에서 끝나는 미사일의 개수.
 * 각 지점에서 수행되는 알고리즘은 다음과 같다.
 * 1. 시작되는 미사일들의 끝나는 시각들을 큐에 삽입한다.
 * 2. 해당 지점에서 끝나는 미사일이 있다면, 큐에 저장되어 있는 시각 정보들을 확인하여 각 시각에서의 끝나는 미사일의 개수를 뺀다.
 *
 */

public class Solution {

    final Map<Integer, Data> map = new TreeMap<>();

    public void service() {
        final int[][] targets = {{4,5},{4,8},{10,14},{11,13},{5,12},{3,7},{1,4}};

        final int answer = solution(targets);
        System.out.println(answer);
    }

    public int solution(final int[][] targets) {
        int answer = 0;

        makeMap(targets);
        answer = calculate();

        return answer;
    }

    private void makeMap(final int[][] targets) {
        for (int[] target : targets) {
            int start = target[0] + 1;
            int end = target[1];

            if (map.get(start) == null) {
                Data data = new Data();
                map.put(start, data);
            }
            if (map.get(end) == null) {
                Data data = new Data();
                map.put(end, data);
            }

            map.get(start).ends.add(end);
            map.get(end).endNum++;
        }
    }

    private int calculate() {
        int interceptorCnt = 0;
        final Queue<Integer> q = new LinkedList<>();

        for (Integer x : map.keySet()) {
            Data data = map.get(x);

            for (int end : data.ends) {
                q.add(end);
            }

            if (data.endNum > 0) {
                while (!q.isEmpty()) {
                    int endX = q.poll();
                    map.get(endX).endNum--;
                }
                interceptorCnt++;
            }
        }
        return interceptorCnt;
    }

    static class Data {
        int endNum = 0;
        List<Integer> ends = new LinkedList<>();
    }
}
