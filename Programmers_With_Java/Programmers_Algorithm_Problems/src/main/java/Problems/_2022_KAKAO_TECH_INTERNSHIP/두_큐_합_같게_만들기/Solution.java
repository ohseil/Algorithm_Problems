package Problems._2022_KAKAO_TECH_INTERNSHIP.두_큐_합_같게_만들기;

import java.util.LinkedList;
import java.util.Queue;

/**
 * 큐를 사용해서 문제에 나와있는 대로 진행하면 한 번 실행할 때마다 시간 복잡도 O(1)로 끝낼 수 있다.
 * 이동 알고리즘은 Greedy 알고리즘으로 합이 더 큰 큐에서 작은 큐로 값을 하나씩 이동하는 방법을 사용했다.
 * 한 번 이동하고 두 큐의 합이 같은지 확인하고 또 한 번 이동하는 식으로 진행했다.
 *
 * 가장 많은 횟수로 이동하는 경우는,
 * 큐의 초기 길이가 n일 때 다시 초기 상태로 돌아오는데 최대 4n번 이동이 가능하기 때문에 이동 횟수는 4n번으로 제한한다.
 */

public class Solution {

    private final Queue<Integer> q1 = new LinkedList<>();
    private final Queue<Integer> q2 = new LinkedList<>();

    private int totalCnt = 0;
    private long total1 = 0;
    private long total2 = 0;

    public void service() {
        int[] queue1 = {3,2,7,2};
        int[] queue2 = {4,6,5,1};

        int answer = solution(queue1, queue2);
        System.out.println(answer);
    }

    public int solution(int[] queue1, int[] queue2) {
        int answer = 0;

        totalCnt = (queue1.length + queue2.length) * 2;

        for (int i = 0; i < queue1.length; i++) {
            q1.add(queue1[i]);
            total1 += queue1[i];
        }
        for (int i = 0; i < queue2.length; i++) {
            q2.add(queue2[i]);
            total2 += queue2[i];
        }

        while (totalCnt-- > 0) {
            if (total1 == total2) {
                break;
            } else if (total1 > total2) {
                q2.add(q1.peek());
                total2 += q1.peek();
                total1 -= q1.peek();
                q1.poll();
            } else if (total1 < total2) {
                q1.add(q2.peek());
                total1 += q2.peek();
                total2 -= q2.peek();
                q2.poll();
            }
            answer++;
        }

        if (total1 != total2) {
            answer = -1;
        }
        return answer;
    }
}