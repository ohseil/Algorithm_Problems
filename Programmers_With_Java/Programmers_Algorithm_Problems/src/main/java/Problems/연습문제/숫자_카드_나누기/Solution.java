package Problems.연습문제.숫자_카드_나누기;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class Solution {

    private List<Integer> divisors;

    private void findDivisors(int num) {

        divisors = new ArrayList<>();

        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                divisors.add(i);
                divisors.add(num / i);
            }
        }

        divisors.add(num);
    }

    boolean canDivideAllElement(int divisor, int[] arr) {
        for (int num : arr)
            if (num % divisor != 0)
                return false;
        return true;
    }

    boolean cantDivideAllElement(int divisor, int[] arr) {
        for (int num : arr)
            if (num % divisor == 0)
                return false;
        return true;
    }

    private int findNumSatisfyConditions(int[] divArr, int[] nonDivArr) {

        Arrays.sort(divArr);
        findDivisors(divArr[0]);

        Collections.sort(divisors, Collections.reverseOrder());

        for (int divisor : divisors) {
            if (canDivideAllElement(divisor, divArr) == true
                && cantDivideAllElement(divisor, nonDivArr) == true)
                return divisor;
        }

        return 0;
    }

    public int solution(int[] arrayA, int[] arrayB) {

        // arrayA를 정렬해서 가장 작은 수 x를 찾는다.
        // x의 약수들을 구한다.
        // 모든 수들을 나눌 수 있어야 하기 때문에
        // 조건에 맞는 수는 구한 약수들에 포함 되어있어야 한다.
        // 구한 약수들을 큰 수부터 차례대로
        // arrayA의 모든 수를 나눠보고 arrayB의 모든 수를 나눠본다.
        // 조건을 처음 만족하는 수가 조건을 만족하는 가장 큰 수이다.

        // 이 과정을 arrayB를 기준으로 한번 더 실행한다.

        int answer = 0;
        int satisfyingNum;

        satisfyingNum = findNumSatisfyConditions(arrayA, arrayB);
        answer = (satisfyingNum > answer) ? satisfyingNum : answer;

        satisfyingNum = findNumSatisfyConditions(arrayB, arrayA);
        answer = (satisfyingNum > answer) ? satisfyingNum : answer;

        return answer;
    }

    public void service() {

        int[] arrayA = { 10, 20 };
        int[] arrayB = { 5, 17 };

        int answer = solution(arrayA, arrayB);
        System.out.println(answer);
    }
}
