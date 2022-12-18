package Problems.스택_큐.같은_숫자는_싫어;

import java.util.Deque;
import java.util.LinkedList;

/*

    deque를 사용했다.
    queue의 역할과 stack의 역할이 모두 가능하기 때문에,
    처음에는 deque를 stack으로 사용해서 숫자들을 순회하면서 stack의 맨 앞 숫자와 비교해서 같지 않는 숫자들만 저장한다.
    그 후 deque를 queue로 사용해서 가장 먼저 저장된 숫자부터 꺼내서 배열을 만든다.

 */

public class Solution {

    private Deque<Integer> deque;

    public void service() {

        int[] arr = {1,1,3,3,0,1,1};

        int[] answer = solution(arr);
        for (int a : answer)
            System.out.print(a + " ");

    }

    public int[] solution(int []arr) {

        int[] answer;

        init();
        inputNums(arr);

        answer = new int[deque.size()];

        outputNumsToArray(answer);

        return answer;
    }

    private void init() {
        deque = new LinkedList<>();
    }

    private void inputNums(final int[] nums) {
        for (int num : nums) {
            if (deque.isEmpty() == true || deque.peekFirst() != num)
                deque.addFirst(num);
        }
    }

    private void outputNumsToArray(int[] arr) {

        int answerIdx = 0;

        while (deque.isEmpty() == false) {
            arr[answerIdx] = deque.pollLast();
            answerIdx++;
        }

    }

}
