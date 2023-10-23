package Problems._2022_KAKAO_TECH_INTERNSHIP.코딩_테스트_공부;

import java.util.LinkedList;
import java.util.Queue;

/**
 * DP 알고리즘과 BFS를 같이 사용해서 문제를 해결했다.
 * 특정 alp, cop에서 도달할 수 있는 alp, cop 값은 문제를 하나 푸는 경우와 alp나 cop를 각각 1씩 올리는 경우에 도달하는 값이다.
 * 시작 alp, cop부터 필요한 최대 alp, cop 까지 dp 알고리즘을 수행한다.
 * 'dp[alp][cop] = 필요한 시간' 구조이다.
 *
 * 여기서 dp만 사용한다면 중간의 모든 alp, cop 조합에서 도달하지 않는 값들도 계산을 거쳐야 한다.
 * 하지만 BFS를 사용한다면, 도달하는 값들만 계산해서 더 적은 계산으로 끝낼 수 있다는 점을 이용했다.
 */

public class Solution {

    private static final int LIMIT = 30000;

    private final Queue<int[]> queue = new LinkedList<>();
    private final int[][] dp = new int[151][151];

    private int needAlp = 0;
    private int needCop = 0;
    private int[][] newProblems;

    public void service() {
        final int alp = 10;
        final int cop = 10;
        final int[][] problems = {{10,15,2,1,2}, {20,20,3,3,4}};

        final int answer = solution(alp, cop, problems);
        System.out.println(answer);
    }

    public int solution(final int alp, final int cop, final int[][] problems) {
        int answer = 0;

        findNeedAlpAndCop(problems);
        makeNewProblems(problems);
        initDP(alp, cop);
        BFS(alp, cop);

        answer = dp[needAlp][needCop];
        return answer;
    }

    private void findNeedAlpAndCop(final int[][] problems) {
        for (int[] problem : problems) {
            needAlp = Math.max(needAlp, problem[0]);
            needCop = Math.max(needCop, problem[1]);
        }
    }

    private void makeNewProblems(final int[][] problems) {
        newProblems = new int[problems.length + 2][problems[0].length];

        for (int i = 0; i < problems.length; i++) {
            newProblems[i] = problems[i];
        }
        newProblems[newProblems.length - 2] = new int[]{0,0,1,0,1};
        newProblems[newProblems.length - 1] = new int[]{0,0,0,1,1};
    }

    private void initDP(final int alp, final int cop) {
        for (int i = 0; i < 151; i++) {
            for (int j = 0; j < 151; j++) {
                dp[i][j] = LIMIT;
            }
        }
        dp[alp][cop] = 0;
    }

    private void BFS(final int alp, final int cop) {
        queue.add(new int[]{alp, cop, 0});

        while (!queue.isEmpty()) {
            int[] data = queue.poll();

            for (int i = 0; i < newProblems.length; i++) {
                int[] newProblem = newProblems[i];
                if (data[0] < newProblem[0] || data[1] < newProblem[1]) {
                    continue;
                }

                int nextAlp = Math.min(needAlp, data[0] + newProblem[2]);
                int nextCop = Math.min(needCop, data[1] + newProblem[3]);
                int nextCost = data[2] + newProblem[4];

                if (dp[nextAlp][nextCop] > nextCost) {
                    dp[nextAlp][nextCop] = nextCost;
                    queue.add(new int[]{nextAlp, nextCop, nextCost});
                }
            }

        }
    }
}
