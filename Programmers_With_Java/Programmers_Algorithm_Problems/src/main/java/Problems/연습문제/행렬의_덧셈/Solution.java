package Problems.연습문제.행렬의_덧셈;

public class Solution {

    public void service() {

        int[][] arr1 = {{1,2}, {2,3}};
        int[][] arr2 = {{3,4}, {5,6}};

        int[][] answer = solution(arr1, arr2);

        for (int r = 0; r < answer.length; r++) {
            for (int c = 0; c < answer[0].length; c++) {
                System.out.print(answer[r][c] + " ");
            }
            System.out.println();
        }

    }

    public int[][] solution(int[][] arr1, int[][] arr2) {

        int[][] answer;

        final int lenRow = arr1.length;
        final int lenCol = arr1[0].length;

        answer = new int[lenRow][lenCol];

        for (int r = 0; r < lenRow; r++)
            for (int c = 0; c < lenCol; c++)
                answer[r][c] = arr1[r][c] + arr2[r][c];

        return answer;
    }

}
