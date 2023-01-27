package Problems.월간_코드_챌린지_시즌3.나머지가_1이_되는_수_찾기;

public class Solution {

    public void service() {

        int n = 10;

        int answer = solution(n);

        System.out.println(answer);

    }

    public int solution(int n) {

        int answer = 0;

        for (int divisor = 2; divisor < n; divisor++) {
            if (n % divisor == 1) {
                answer = divisor;
                break;
            }
        }

        return answer;
    }

}
