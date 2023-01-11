package Problems.연습문제.최대공약수와_최소공배수;

/*

    유클리드 호제법 사용.

 */

public class Solution {

    public void service() {

        int n = 3;
        int m = 12;

        int[] answer = solution(n, m);
        for (int a : answer)
            System.out.print(a + " ");

    }

    public int[] solution(int n, int m) {

        int[] answer = new int[2];

        int gcd;
        int lcm;

        if (n > m) gcd = findGCD(n, m);
        else gcd = findGCD(m, n);

        lcm = n * m / gcd;

        answer[0] = gcd;
        answer[1] = lcm;

        return answer;
    }

    private int findGCD(int bigNum, int smallNum) {
        if (bigNum % smallNum == 0) return smallNum;
        return findGCD(smallNum, bigNum % smallNum);
    }

}
