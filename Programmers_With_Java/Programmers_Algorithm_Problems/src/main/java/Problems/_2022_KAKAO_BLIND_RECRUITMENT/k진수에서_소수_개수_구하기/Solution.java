package Problems._2022_KAKAO_BLIND_RECRUITMENT.k진수에서_소수_개수_구하기;

public class Solution {

    public void service() {
        int n = 437674;
        int k = 3;

        int answer = solution(n, k);
        System.out.println(answer);
    }

    public int solution(int n, final int k) {
        int answer = 0;

        while (n > 0) {
            long num = 0;
            long tenMulti = 1;

            while (n % k > 0) {
                num += (n % k) * tenMulti;
                n /= k;
                tenMulti *= 10;
            }
            n /= k;

            if (isPrime(num)) {
                answer++;
            }
        }
        return answer;
    }

    private boolean isPrime(final long num) {
        if (num < 2) {
            return false;
        }

        for (long i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
}
