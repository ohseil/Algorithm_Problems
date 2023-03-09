package Problems.연습문제.테이블_해시_함수;

import java.util.*;

public class Solution implements Comparator<int[]> {

    private int col;

    public void service() {
        final int[][] table = {{2,2,6},{1,5,10},{4,2,9},{3,8,3}};
        final int col = 2;
        final int rowBegin = 2;
        final int rowEnd = 3;

        final int answer = solution(table, col, rowBegin, rowEnd);
        System.out.println(answer);
    }

    @Override
    public int compare(int[] o1, int[] o2) {
        if (o1[col] - o2[col] < 0) {
            return -1;
        } else if (o1[col] - o2[col] == 0) {
            if (o1[0] - o2[0] > 0) {
                return -1;
            } else if (o1[0] == o1[0]) {
                return 0;
            }
        }
        return 1;
    }

    public int solution(final int[][] table, int col, int row_begin, int row_end) {
        int answer = 0;
        this.col = col - 1;

        List<int[]> tableList = Arrays.asList(table);
        tableList.sort(this);

        for (int r = (row_begin - 1); r <= (row_end - 1); r++) {
            int modSum = 0;
            for (int c = 0; c < tableList.get(0).length; c++) {
                modSum += tableList.get(r)[c] % (r + 1);
            }
            answer ^= modSum;
        }
        return answer;
    }
}
