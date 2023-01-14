package Problems.연습문제.평균_구하기;

public class Solution {

    public void service() {

        int[] arr = {1,2,3,4};

        double answer = solution(arr);
        System.out.println(answer);

    }

    public double solution(int[] arr) {

        double answer = 0;

        for (int num : arr)
            answer += num;

        answer /= arr.length;

        return answer;
    }

}
