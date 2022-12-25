package Problems.연습문제.소수_찾기;

/*

    에라토스테네스의 체 알고리즘 사용.

 */

public class Solution {

    private static final int LIMIT_NUM = 1000000;

    private int[] primeFlags;

    public void service() {

        int n = 10;

        int answer = solution(n);
        System.out.println(answer);

    }

    public int solution(int n) {

        int answer = 0;

        init();
        findPrimeNumbers();

        for (int num = 2; num <= n; num++)
            if (primeFlags[num] == 0) answer++;

        return answer;
    }

    private void init() {
        primeFlags = new int[LIMIT_NUM + 1];
    }

    private void findPrimeNumbers() {

        for (int i = 2; i * i <= LIMIT_NUM; i++) {

            if (primeFlags[i] == 1) continue;

            for (int j = i * i; j <= LIMIT_NUM; j += i)
                primeFlags[j] = 1;

        }

    }

}
