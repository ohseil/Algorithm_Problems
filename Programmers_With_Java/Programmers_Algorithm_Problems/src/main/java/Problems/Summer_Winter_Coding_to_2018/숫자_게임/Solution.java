package Problems.Summer_Winter_Coding_to_2018.숫자_게임;

import java.util.Arrays;

/*

    가장 많은 승점을 얻기 위해서는
    B에서 최대한 작은 숫자로 A에서 최대한 큰 숫자를 이기도록 해야 한다.

    A와 B 배열을 오름차순으로 정렬한다.
    A와 B에서 차례대로 숫자를 꺼낸다.
    A의 숫자를 B의 숫자가 이긴다면 두 배열 모두 다음 숫자를 꺼낸다.
    A의 숫자를 B의 숫자가 이길 수 없다면 B에서 다음 숫자를 꺼낸다.
    두 배열 중 하나라도 모든 숫자를 꺼내게 되면 작업을 종료한다.

 */

public class Solution {

    public void service() {

        int[] A = {5,1,3,7};
        int[] B = {2,2,6,8};

        int answer = solution(A, B);
        System.out.println(answer);

    }

    public int solution(int[] A, int[] B) {

        int answer = 0;
        int aIdx = 0;
        int bIdx = 0;

        Arrays.sort(A);
        Arrays.sort(B);

        while (aIdx < A.length && bIdx < B.length) {

            if (B[bIdx] > A[aIdx]) {
                answer++;
                aIdx++;
                bIdx++;
            }
            else
                bIdx++;

        }

        return answer;
    }

}
