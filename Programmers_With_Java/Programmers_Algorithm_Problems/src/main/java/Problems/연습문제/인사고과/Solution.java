package Problems.연습문제.인사고과;

import java.util.Arrays;

/**
 * 이 문제에서 해결해야 할 핵심 문제는 인센티브를 받지 못하는 인원을 확인하는 방법이다.
 * 가장 간단한 방법은 모든 인원과 비교하는 방법이지만, 최악의 경우에 시간 복잡도가 매우 커진다.
 * 적은 시간 복잡도로 해결하기 위해 다음과 같은 방법을 사용한다.
 *
 * 1. 근무 태도 점수를 기준으로 내림 차순 정렬하고, 만약 근무 태도 점수가 같다면 동료 평가 점수를 기준으로 오름 차순 정렬한다.
 * 2. 정렬한 배열을 차례대로 순회하면서 확인한다.
 *    순회하면서 동료 평가 점수의 최대 값을 저장한다.
 *    특정 사원이 인센티브를 못받는 경우는 이전 index들에 해당하는 사원들 중에 동료 평가 점수가 높은 사원이 한 명이라도 있는 경우다.
 *    순회하면서 저장해 놓았던 동료 평가 점수와 비교하는 것만으로 구분할 수 있게 된다.
 * 결국, 한 번의 순회로 인센티브를 받을 수 있는 사원들을 선별할 수 있다.
 * 이 알고리즘을 기반으로 문제를 해결했다.
 */

public class Solution {

    public void service() {
        final int[][] scores = {{2,2},{1,4},{3,2},{3,2},{2,1}};

        final int answer = solution(scores);
        System.out.println(answer);
    }

    public int solution(int[][] scores) {
        int answer = 1;
        int[] scoreWonho = scores[0];

        Arrays.sort(
                scores,
                (int[] lhs, int[] rhs) -> (lhs[0] != rhs[0]) ? (rhs[0] - lhs[0]) : (lhs[1] - rhs[1])
        );

        int maxScore1 = 0;

        for (int[] score : scores) {
            if (score[1] < maxScore1) {
                if (score.equals(scoreWonho)) {
                    return -1;
                }
                continue;
            }

            if (score[0] + score[1] > scoreWonho[0] + scoreWonho[1]) {
                answer++;
            }
            maxScore1 = Math.max(maxScore1, score[1]);
        }
        return answer;
    }
}
