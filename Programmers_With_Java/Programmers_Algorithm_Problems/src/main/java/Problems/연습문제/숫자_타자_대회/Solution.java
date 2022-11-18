package Problems.연습문제.숫자_타자_대회;

import java.util.HashMap;
import java.util.Map;
import java.util.Objects;

import static java.lang.Integer.MAX_VALUE;

public class Solution {

    private class FingerPos {

        private final int lPos;
        private final int rPos;

        FingerPos(int lPos, int rPos) {
            this.lPos = lPos;
            this.rPos = rPos;
        }

        public int getlPos() {
            return lPos;
        }

        public int getrPos() {
            return rPos;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            FingerPos fingerPos = (FingerPos) o;
            return lPos == fingerPos.lPos && rPos == fingerPos.rPos;
        }

        @Override
        public int hashCode() {
            return Objects.hash(lPos, rPos);
        }
    }

    private final int costs[][] = { { 1, 7, 6, 7, 5, 4, 5, 3, 2, 3 },
                                    { 7, 1, 2, 4, 2, 3, 5, 4, 5, 6 },
                                    { 6, 2, 1, 2, 3, 2, 3, 5, 4, 5 },
                                    { 7, 4, 2, 1, 5, 3, 2, 6, 5, 4 },
                                    { 5, 2, 3, 5, 1, 2, 4, 2, 3, 5 },
                                    { 4, 3, 2, 3, 2, 1, 2, 3, 2, 3 },
                                    { 5, 5, 3, 2, 4, 2, 1, 5, 3, 2 },
                                    { 3, 4, 5, 6, 2, 3, 5, 1, 2, 4 },
                                    { 2, 5, 4, 5, 3, 2, 3, 2, 1, 2 },
                                    { 3, 6, 5, 4, 5, 3, 2, 4, 2, 1 } };

    private Map<FingerPos, Integer> hmapTypingCostAndFingerPos = new HashMap<>();
    private Map<FingerPos, Integer> hmapCurTypingCostAndFingerPos = new HashMap<>();

    private boolean canMove(FingerPos fingerPos, int cost) {
        return (hmapCurTypingCostAndFingerPos.containsKey(fingerPos) == false
                || hmapCurTypingCostAndFingerPos.get(fingerPos) > cost);
    }

    private void pressNumberButton(int number) {

        for (FingerPos fingerPos : hmapTypingCostAndFingerPos.keySet()) {

            int lFinger = fingerPos.getlPos();
            int rFinger = fingerPos.getrPos();
            int totalCost = hmapTypingCostAndFingerPos.get(fingerPos);

            FingerPos nextFingerPos;

            if (number == lFinger) {

                nextFingerPos = new FingerPos(number, rFinger);
                if (canMove(nextFingerPos, totalCost + 1) == true)
                    hmapCurTypingCostAndFingerPos.put(nextFingerPos, totalCost + 1);
            }
            else if (number == rFinger) {

                nextFingerPos = new FingerPos(lFinger, number);
                if (canMove(nextFingerPos, totalCost + 1) == true)
                    hmapCurTypingCostAndFingerPos.put(nextFingerPos, totalCost + 1);
            }
            else {

                nextFingerPos = new FingerPos(number, rFinger);
                if (canMove(nextFingerPos, totalCost + costs[lFinger][number]) == true)
                    hmapCurTypingCostAndFingerPos.put(nextFingerPos, totalCost + costs[lFinger][number]);

                nextFingerPos = new FingerPos(lFinger, number);
                if (canMove(nextFingerPos, totalCost + costs[rFinger][number]) == true)
                    hmapCurTypingCostAndFingerPos.put(nextFingerPos, totalCost + costs[rFinger][number]);
            }

        }

    }

    private int findMinTotalCost() {

        int minTotalCost = MAX_VALUE;

        for (FingerPos fingerPos : hmapTypingCostAndFingerPos.keySet()) {

            int totalCost = hmapTypingCostAndFingerPos.get(fingerPos);

            if (minTotalCost > totalCost)
                minTotalCost = totalCost;
        }

        return minTotalCost;
    }

    public int solution(String numbers) {

        // 기본 알고리즘은 bfs다.
        // 각 상태 값은 왼쪽 엄지 위치, 오른쪽 엄지 위치, 현재까지의 총 비용이다.
        // 해당 데이터를 가지고 탐색을 진행한다.

        // 각 숫자마다 queue에 있는 data를 모두 꺼내서 확인하는 방식인데,
        // 여기서는 queue 대신 hash map을 사용했다.
        // 이유는 불가능한 경로를 제거해 주기 위해서다.
        // 같은 숫자를 누르는 과정에서 같은 손가락의 위치를 가진 경로의 총 비용이 다르다면,
        // 가장 비용이 적은 경로만 남기고 제거해 줘야한다.
        // hash map을 통해서 각 숫자 탐색마다 불가능한 경로를 제거해 준다.

        // hash map에 저장 된 경로들을 다음 숫자 탐색에 사용한다.

        // 각 경로를 탐색하는 조건은 다음과 같다.
        // 1. if (눌러야 하는 숫자 == 왼쪽 엄지 위치의 숫자) 경로가 하나다.
        // 2. if (눌러야 하는 숫자 == 오른쪽 엄지 위치의 숫자) 경로가 하나다.
        // 3. 왼쪽 엄지로 누르는 경우와 오른쪽 엄지로 누르는 경우 2가지 경로가 있다.
        // 각 다음 경로마다 같은 손가락 위치의 경로의 비용을 확인해서 불가능한 경로는 더 이상 진행하지 않는다.

        int answer = 0;

        hmapTypingCostAndFingerPos.put(new FingerPos(4, 6), 0);

        for (int i = 0; i < numbers.length(); i++) {

            int number = numbers.charAt(i) - 48;

            hmapCurTypingCostAndFingerPos = new HashMap<>();

            pressNumberButton(number);

            hmapTypingCostAndFingerPos = hmapCurTypingCostAndFingerPos;
        }

        answer = findMinTotalCost();

        return answer;
    }

    public void service() {

        String numbers= "1756";

        int answer = solution(numbers);
        System.out.println(answer);
    }
}
