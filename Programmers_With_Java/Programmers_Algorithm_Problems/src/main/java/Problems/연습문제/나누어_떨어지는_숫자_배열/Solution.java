package Problems.연습문제.나누어_떨어지는_숫자_배열;

import java.util.*;

public class Solution {

    private List<Integer> canDividedNumList;

    public void service() {

        int[] arr = {5,9,7,10};
        int divisor = 5;

        int[] answer = solution(arr, divisor);
        for (int a : answer)
            System.out.print(a + " ");

    }

    public int[] solution(int[] arr, int divisor) {

        int[] answer;

        init();
        findCanDividedNums(arr, divisor);

        if (canDividedNumList.isEmpty() == true) answer = new int[]{-1};
        else answer = getSortedCanDividedNums();

        return answer;
    }

    private void init() {
        canDividedNumList = new ArrayList<>();
    }

    private void findCanDividedNums(int[] numList, int divisor) {
        for (int num : numList) {
            if (num % divisor == 0)
                canDividedNumList.add(num);
        }
    }

    private int[] getSortedCanDividedNums() {

        int[] sortedCanDividedNums;

        Collections.sort(canDividedNumList);

        sortedCanDividedNums = new int[canDividedNumList.size()];

        for (int i = 0; i < canDividedNumList.size(); i++)
            sortedCanDividedNums[i] = canDividedNumList.get(i);

        return sortedCanDividedNums;
    }

}
