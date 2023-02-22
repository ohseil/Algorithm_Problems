package Problems.연습문제.콜라_문제;

public class Solution {

    public void service() {
        final int a = 2;
        final int b = 1;
        final int n = 20;

        final int answer = solution(a, b, n);
        System.out.println(answer);
    }

    public int solution(final int needEmptyBottleCnt, final int canGetCokeCnt, int emptyBottleCnt) {
        int answer = 0;

        while (emptyBottleCnt >= needEmptyBottleCnt) {
            final int getCokeCnt = (emptyBottleCnt / needEmptyBottleCnt) * canGetCokeCnt;
            answer += getCokeCnt;
            emptyBottleCnt = (emptyBottleCnt % needEmptyBottleCnt) + getCokeCnt;
        }

        return answer;
    }
}
