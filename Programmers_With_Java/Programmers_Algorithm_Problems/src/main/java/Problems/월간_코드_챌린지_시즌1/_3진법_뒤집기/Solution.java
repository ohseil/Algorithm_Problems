package Problems.월간_코드_챌린지_시즌1._3진법_뒤집기;

public class Solution {

    private StringBuilder num;

    public Solution() {
        num = new StringBuilder();
    }

    public void service() {

        int n = 45;

        int answer = solution(n);
        System.out.println(answer);

    }

    public int solution(int n) {

        int answer = 0;

        num.append(n);

        decimalToTernary();
        num.reverse();
        ternaryToDecimal();

        answer = Integer.parseInt(num.toString());

        return answer;
    }

    private void decimalToTernary() {

        long ternaryNum = 0;
        long n = Long.parseLong(num.toString());
        long ten = 1;

        while (n > 0) {
            ternaryNum += (n % 3) * ten;
            n /= 3;
            ten *= 10;
        }

        num = new StringBuilder().append(ternaryNum);

    }

    private void ternaryToDecimal() {

        long decimalNum = 0;
        long three = 1;

        for (int i = num.length() - 1; i >= 0; i--) {
            int digit = Integer.parseInt(num.substring(i, i + 1));
            decimalNum += digit * three;
            three *= 3;
        }

        num = new StringBuilder().append(decimalNum);

    }

}
