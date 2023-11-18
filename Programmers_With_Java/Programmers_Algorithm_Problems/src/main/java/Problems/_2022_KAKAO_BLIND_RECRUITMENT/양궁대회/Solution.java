package Problems._2022_KAKAO_BLIND_RECRUITMENT.양궁대회;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

/**
 * 어피치가 쏜 횟수보다 많게 쏘지 않으면 의미가 없다. 화살 낭비다.
 * 그리고 어피치가 쏜 횟수보다 1개만 많게 쏘면 점수를 한 번 얻고 끝이다.
 * 최대 효율로 특정 점수를 얻는 방법은 어피치보다 1개만 더 쏘는 것이다.
 *
 * 이 정보를 바탕으로 라이언이 특정 점수를 얻거나 얻지 않도록 해서 모든 경우를 탐색하는 완전 탐색을 진행한다.
 * 최악의 경우에도 시간 복잡도는 10!이기 때문에 시간 초과가 나지 않는다.
 */

public class Solution {

    private final Queue<Node> q = new LinkedList<>();
    private int maxDif = 0;

    public void service() {
        int n = 5;
        int[] info = {2,1,1,1,0,0,0,0,0,0,0};

        int[] answer = solution(n, info);
        for (int a : answer) {
            System.out.print(a + " ");
        }
    }

    public int[] solution(int n, int[] info) {
        int[] answer;

        findInitMaxDif(info);
        answer = findAnswer(n, info);
        return answer;
    }

    private void findInitMaxDif(int[] info) {
        for (int i = 0; i < info.length; i++) {
            if (info[i] > 0) {
                maxDif -= (10 - i);
            }
        }
    }

    private int[] findAnswer(int n, int[] info) {
        int[] answer = new int[11];

        q.add(new Node(new int[11], n, maxDif));

        while (!q.isEmpty()) {
            Node node = q.poll();
            boolean isNext = false;

            if (node.restCnt == 0) {
                answer = checkAndUpdate(node, answer);
                continue;
            }

            for (int i = 0; i < 11; i++) {
                if (node.validations[i] > 0) {
                    continue;
                }
                if (node.restCnt <= info[i]) {
                    continue;
                }

                q.add(node.makeNext(i, info[i]));
                isNext = true;
            }

            if (!isNext) {
                q.add(node.makeLast());
            }
        }

        if (maxDif <= 0) {
            return new int[]{-1};
        }
        return answer;
    }

    private int[] checkAndUpdate(Node node, int[] answer) {
        if (node.scoreDif > maxDif) {
            maxDif = node.scoreDif;
            return node.validations;
        } else if (node.scoreDif == maxDif) {
            for (int i = 10; i >= 0; i--) {
                if (node.validations[i] > answer[i]) {
                    maxDif = node.scoreDif;
                    return node.validations;
                }
            }
        }
        return answer;
    }

    static class Node {
        final int[] validations;
        final int restCnt;
        final int scoreDif;

        Node(int[] validations, int restCnt, int scoreDif) {
            this.validations = validations;
            this.restCnt = restCnt;
            this.scoreDif = scoreDif;
        }

        Node makeNext(final int targetNum, final int arrowCnt) {
            int[] nextValidations = Arrays.copyOf(validations, 11);
            int nextRestCnt = restCnt;
            int nextDif = scoreDif;

            if (arrowCnt > 0) {
                nextValidations[targetNum] = (arrowCnt + 1);
                nextRestCnt -= (arrowCnt + 1);
                nextDif += (10 - targetNum) * 2;
            } else {
                nextValidations[targetNum] = 1;
                nextRestCnt--;
                nextDif += (10 - targetNum);
            }
            return new Node(nextValidations, nextRestCnt, nextDif);
        }

        Node makeLast() {
            validations[10] += restCnt;
            return new Node(validations, 0, scoreDif);
        }
    }
}
