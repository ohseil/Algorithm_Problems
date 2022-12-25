package Problems.코딩테스트_입문.최빈값_구하기;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Solution {

    private int[] numOfDigitList;
    private List<int[]> sortedList;

    public void service() {

        int[] arr = {1, 2, 3, 3, 3, 4};

        int answer = solution(arr);
        System.out.println(answer);

    }

    public int solution(int[] array) {

        int answer = 0;

        init();
        countNumOfDigit(array);
        makeSortedList();

        answer = findMostFrequentDigit();

        return answer;
    }

    private void init() {
        numOfDigitList = new int[1000];
        sortedList = new ArrayList<>();
    }

    private void countNumOfDigit(final int[] digits) {
        for (int num : digits)
            numOfDigitList[num]++;
    }

    private void makeSortedList() {

        for (int i = 0; i < 1000; i++)
            sortedList.add(new int[]{i, numOfDigitList[i]});

        Collections.sort(sortedList, (int[] o1, int[] o2) -> o2[1] - o1[1]);

    }

    private int findMostFrequentDigit() {

        for (int i = 1; i < sortedList.size(); i++) {
            if (sortedList.get(i)[1] == sortedList.get(0)[1])
                return -1;
        }

        return sortedList.get(0)[0];
    }

}
