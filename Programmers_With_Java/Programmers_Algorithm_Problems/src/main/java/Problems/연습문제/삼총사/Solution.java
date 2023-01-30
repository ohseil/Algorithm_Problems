package Problems.연습문제.삼총사;

import java.util.ArrayList;
import java.util.List;

public class Solution {

    private static final int ELEMENT_CNT_IN_COMBINATION = 3;

    private int zeroSumCnt = 0;

    public void service() {

        int[] number = {-2, 3, 0, 2, -5};

        int answer = solution(number);

        System.out.println(answer);

    }

    public int solution(int[] number) {

        int answer = 0;

        findCombinations(number, new ArrayList<>(), -1);

        answer = zeroSumCnt;

        return answer;
    }

    private void findCombinations(final int[] numbers, List<Integer> combination, final int addedIdx) {

        if (combination.size() == ELEMENT_CNT_IN_COMBINATION) {

            if (isZeroSum(combination) == true)
                zeroSumCnt++;

            return;
        }

        for (int i = addedIdx + 1; i < (numbers.length - ELEMENT_CNT_IN_COMBINATION + 1 + combination.size()); i++) {

            List<Integer> nextCombination = new ArrayList<>(combination);
            int addingNum = numbers[i];

            nextCombination.add(addingNum);
            findCombinations(numbers, nextCombination, i);

        }

    }

    private boolean isZeroSum(final List<Integer> numbers) {

        int sum = 0;

        for (int number : numbers)
            sum += number;

        return sum == 0;
    }

}
