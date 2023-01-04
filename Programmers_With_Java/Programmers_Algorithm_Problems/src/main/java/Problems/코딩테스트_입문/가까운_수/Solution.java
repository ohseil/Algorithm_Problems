package Problems.코딩테스트_입문.가까운_수;

public class Solution {

    public void service() {

        int[] array = {3,10,28};
        int n = 20;

        int answer = solution(array, n);
        System.out.println(answer);

    }

    public int solution(int[] array, int n) {

        int answer = array[0];
        int dif = Math.abs(n - array[0]);

        for (int i = 1; i < array.length; i++) {
            if (Math.abs(n - array[i]) < dif
                    || (Math.abs(n - array[i]) == dif && array[i] < answer)) {
                answer = array[i];
                dif = Math.abs(n - array[i]);
            }
        }

        return answer;
    }

}
