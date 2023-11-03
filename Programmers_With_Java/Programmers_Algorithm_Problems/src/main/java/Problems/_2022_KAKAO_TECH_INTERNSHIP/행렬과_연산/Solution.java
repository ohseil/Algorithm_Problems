package Problems._2022_KAKAO_TECH_INTERNSHIP.행렬과_연산;

import java.util.Deque;
import java.util.LinkedList;

/**
 * Brute Force 알고리즘을 사용하면 시간이 너무 오래 걸린다.
 * 정확성 테스트는 통과할 수 있지만 효율성은 통과할 수 없다.
 *
 * 시간 복잡도를 줄이기 위해 Deque를 사용했다.
 * 행렬의 양쪽 끝의 열을 각각 하나의 Deque로 구성하고,
 * 중간의 행렬은 Deque를 원소로 하는 Deque를 사용한다.
 * 자세하게 설명하자면, 양쪽 끝 열을 제외한 행렬에서
 * 각 행을 하나의 Deque로 구성한 후에 해당 행을 하나의 원소로 해서 하나의 Deque로 또 구성한다.
 * 자료형은 Deque<Deque<Integer>> 형태가 된다.
 * 위에서 구성한 Deque를 각각 leftDeque, rightDeque, midDeque라 부르기로 했다.
 *
 * 이렇게 구성한 이유는 행렬 연산의 특징과 Deque의 특징을 이용해서 시간 복잡도를 줄이기 위함이다.
 * - Shift Row 명령의 경우,
 *   위에서 구성한 3개의 Deque에서 원소를 앞에서 하나 빼서 뒤에 넣는 동작만으로 수행이 가능하다.
 * - Rotate 명령의 경우,
 *   leftDeque의 위에서 뽑아서 midDeque의 가장 위쪽 Deque의 왼쪽에 삽입하고,
 *   midDeque의 가장 위쪽 Deque에서 맨 오른쪽 원소를 뽑아 rightDeque의 위쪽에 삽입한다.
 *   이 과정을 행렬의 아래쪽에서도 해주면 O(1)의 시간 복잡도로 수행된다.
 *
 * 위와 같은 방법으로 각 명령어를 수행하는 시간 복잡도는 O(1)이 되기 때문에
 * 모든 명령어를 수행하는 시간 복잡도는 O(명령어 개수)가 된다.
 */

public class Solution {

    private static final String SHIFT_ROW = "ShiftRow";
    private static final String ROTATE = "Rotate";

    private int rLen;
    private int cLen;
    private Deque<Integer> leftDeque = new LinkedList<>();
    private Deque<Integer> rightDeque = new LinkedList<>();
    private Deque<Deque<Integer>> midDeque = new LinkedList<>();

    public void service() {
        int[][] rc = new int[][]{{1,2,3},{4,5,6},{7,8,9}};
        String[] operations = new String[]{"Rotate", "ShiftRow"};

        int[][] answer = solution(rc, operations);

        for (int[] ans : answer) {
            for (int a : ans) {
                System.out.print(a + " ");
            }
            System.out.println();
        }
    }

    public int[][] solution(int[][] rc, final String[] operations) {
        int[][] answer = {};

        rLen = rc.length;
        cLen = rc[0].length;

        makeDeques(rc);

        for (String operation : operations) {
            if (operation.equals(SHIFT_ROW)) {
                shiftRow();
            } else {
                rotate();
            }
        }

        answer = new int[rLen][cLen];

        for (int r = 0; r < rLen; r++) {
            Deque<Integer> mid = midDeque.pollLast();

            for (int c = 1; c < cLen - 1; c++) {
                answer[r][c] = mid.pollLast();
            }
            answer[r][0] = leftDeque.pollLast();
            answer[r][cLen - 1] = rightDeque.pollLast();
        }
        return answer;
    }

    private void makeDeques(final int[][] rc) {
        for (int r = 0; r < rLen; r++) {
            Deque<Integer> dq = new LinkedList<>();

            for (int c = 1; c < cLen - 1; c++) {
                dq.addFirst(rc[r][c]);
            }
            midDeque.addFirst(dq);
            leftDeque.addFirst(rc[r][0]);
            rightDeque.addFirst(rc[r][cLen - 1]);
        }
    }

    private void shiftRow() {
        midDeque.addLast(midDeque.pollFirst());
        leftDeque.addLast(leftDeque.pollFirst());
        rightDeque.addLast(rightDeque.pollFirst());
    }

    private void rotate() {
        midDeque.peekLast().addLast(leftDeque.pollLast());
        rightDeque.addLast(midDeque.peekLast().pollFirst());
        midDeque.peekFirst().addFirst(rightDeque.pollFirst());
        leftDeque.addFirst(midDeque.peekFirst().pollLast());
    }
}
