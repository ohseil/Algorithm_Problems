package Problems.연습문제.제일_작은_수_제거하기;

public class Solution {

    public void service() {

        int[] arr = {4,3,2,1};

        int[] answer = solution(arr);
        for (int a : answer)
            System.out.print(a + " ");

    }

    public int[] solution(int[] arr) {

        int[] answer = {};

        if (arr.length == 1) {
            answer = new int[]{-1};
            return answer;
        }

        answer = new int[arr.length - 1];

        int answerIdx = 0;
        int minNum = findMinNum(arr);

        for (int i = 0; i < arr.length; i++) {

            if (arr[i] == minNum)
                continue;

            answer[answerIdx] = arr[i];
            answerIdx++;

        }

        return answer;
    }

    private int findMinNum(int[] arr) {

        int minNum = arr[0];

        for (int i = 1; i < arr.length; i++) {
            if (arr[i] < minNum)
                minNum = arr[i];
        }

        return minNum;
    }

}
