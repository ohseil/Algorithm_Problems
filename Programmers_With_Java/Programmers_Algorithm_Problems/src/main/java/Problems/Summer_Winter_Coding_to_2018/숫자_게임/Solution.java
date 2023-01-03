package Problems.Summer_Winter_Coding_to_2018.숫자_게임;

import java.util.Arrays;

/*

    가장 많은 승점을 얻기 위해서는
    B와 A에서 작은 숫자부터 꺼내서 비교해 나가거나
    큰 숫자부터 꺼내서 비교해 나가면 된다.

    왜냐하면 임의의 숫자를 A에서 꺼냈을 때,
    B에서 이기게 하기 위해서 숫자를 꺼내야 하는데 여러 숫자가 있는 경우
    최선의 선택지는 이 중 가장 작은 숫자이기 때문이다.
    따라서 최대 효율로 이기게 하기 위해서는
    작은 순서로 꺼내서 이길 수 있다면 이 숫자가 최선의 선택이 되도록 한다.
    또는 큰 순서로 꺼내서 마찬가지로 꺼낸 숫자가 최선의 선택이 되도록 한다.

    이 풀이에서는 작은 숫자부터 꺼내는 방법을 사용했다.
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
