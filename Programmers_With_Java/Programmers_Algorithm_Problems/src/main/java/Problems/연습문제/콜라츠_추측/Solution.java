package Problems.연습문제.콜라츠_추측;

public class Solution {

    public void service() {

        int num = 6;

        int answer = solution(num);
        System.out.println(answer);

    }

    public int solution(int num) {

        int answer = 0;

        answer = collatzGuess(num);

        if (answer > 500) answer = -1;

        return answer;
    }

    private int collatzGuess(long num) {

        if (num == 1) return 0;

        if (num % 2 == 0) return 1 + collatzGuess(num / 2);
        else return 1 + collatzGuess(num * 3 + 1);

    }

}
