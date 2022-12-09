package Problems.연습문제.디펜스_게임;

import java.util.Collections;
import java.util.PriorityQueue;

public class Solution {

    private PriorityQueue<Integer> priorityQueue;
    private int numOfUnits;
    private int numOfInvincibilityTickets;
    private int highestClearRoundNum;

    private void init(final int numOfUnits, final int numOfInvincibilityTickets) {
        priorityQueue = new PriorityQueue<>(Collections.reverseOrder());
        this.numOfUnits = numOfUnits;
        this.numOfInvincibilityTickets = numOfInvincibilityTickets;
        this.highestClearRoundNum = 0;
    }

    private boolean canDefendEnemyAttacks(final int numOfEnemies) {
        return numOfUnits >= numOfEnemies;
    }

    private void useInvincibilityTicket() {
        int maxNumOfEnemiesInBeforeRounds = priorityQueue.poll();
        numOfUnits += maxNumOfEnemiesInBeforeRounds;
        numOfInvincibilityTickets--;
    }

    private void defendEnemyAttacks(final int[] numOfEnemiesList) {

        for (int i = 0; i < numOfEnemiesList.length; i++) {

            int round = i + 1;
            int numOfEnemies = numOfEnemiesList[i];

            priorityQueue.add(numOfEnemies);

            while (canDefendEnemyAttacks(numOfEnemies) == false && numOfInvincibilityTickets > 0) {
                useInvincibilityTicket();
            }

            if (canDefendEnemyAttacks(numOfEnemies) == false)
                break;

            highestClearRoundNum = round;
            numOfUnits -= numOfEnemies;

        }

    }

    public int solution(int n, int k, int[] enemy) {

        /*

            먼저 무적권을 쓰지 않고 라운드를 진행한다고 생각해 보자.
            어느 순간 막히는 라운드가 생긴다면,
            무적권을 사용할 수 있다.
            이때, 최대한 많은 라운드를 깨기 위해서는
            무적권을 최대한 효율적으로 사용해야 한다.

            이 상황에서 무적권을 가장 효율적으로 사용하는 방법은
            현재 막힌 라운드를 포함한 이전 라운드들의 적 숫자 중,
            가장 많은 적이 나온 라운드에서 무적권을 사용하면 된다.

            무적권을 사용해도 못 깬다면 남은 무적권 횟수만큼 더 사용하면 된다.
            무적권 횟수를 모두 사용해도 못 깬다면 더 이상 방법이 없는 것을 의미한다.

            여기서 무적권을 효율적으로 사용하는 방법을 자세하게 보면,
            막히는 라운드마다 막힌 라운드를 포함한 이전 라운드들의 적 숫자를 정렬해야 한다는 것을 알 수 있다.
            하지만 문제에서 주어지는 최대 라운드 수나 무적권 숫자 등을 고려한다면,
            이 정렬 과정을 막히는 라운드마다 진행하는 것은 시간이 너무 오래 걸린다.

            따라서, max heap으로 구현되어 있는 priority queue를 사용했다.
            매 라운드마다 적 숫자를 queue에 넣고,
            무적권을 사용할 때마다 queue에서 하나씩 꺼내서 처리한다. 꺼낸 숫자는 가장 큰 적 숫자가 될 것이다.

            라운드의 최대 수는 100만 개다.
            heap 자료구조의 삽입, 삭제 시간 복잡도는 O(logn)이다.
            최대로 삽입하는 경우는 100만 x log100만 미만의 시간 복잡도가 될 것이다.
            그리고 꺼내서 확인하는 경우는 무적권을 사용하는 경우인데,
            무적권은 최대 50만 개다.
            따라서, 이 경우도 최대 시간 복잡도는 50만 x log100만 미만이 된다.
            이 시간 복잡도면 충분히 문제를 푸는 데 오래 걸리지 않는다.

         */

        int answer = 0;

        init(n, k);
        defendEnemyAttacks(enemy);

        answer = highestClearRoundNum;

        return answer;
    }

    public void service() {

        int n = 7;
        int k = 3;
        int[] enemyList = {4,2,4,5,3,3,1};

        int answer = solution(n, k, enemyList);
        System.out.println(answer);

    }
}
