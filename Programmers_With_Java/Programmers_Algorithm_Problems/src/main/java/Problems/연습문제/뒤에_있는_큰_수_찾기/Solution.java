package Problems.연습문제.뒤에_있는_큰_수_찾기;

import java.util.PriorityQueue;

/**
 * Priority Queue를 사용했다.
 * Priority Queue에 저장된 정보는 숫자의 index와 numbers[index] 값이다.
 * 정렬 기준은 값이 작은 순서다.
 *
 * numbers의 숫자를 차례대로 순회한다.
 * queue에서 하나씩 숫자를 꺼내어 현재 숫자와 비교해서 현재 숫자가 더 크면 queue에서 꺼낸 숫자의 뒷 큰수에 해당한다.
 * queue에서 조건에 맞는 수들을 꺼내어 계산한 후에 현재 수를 queue에 저장한다.
 */

public class Solution {

    static class Data implements Comparable<Data> {
        private final int idx;
        private final int num;

        public Data(final int idx, final int num) {
            this.idx = idx;
            this.num = num;
        }

        @Override
        public int compareTo(Data o) {
            return this.num - o.num;
        }
    }

    public void service() {
        final int[] numbers = {2, 3, 3, 5};

        final int[] answer = solution(numbers);
        for (int a : answer) {
            System.out.print(a + " ");
        }
        System.out.println();
    }

    public int[] solution(final int[] numbers) {
        final int[] answer = new int[numbers.length];

        setUp(answer);

        PriorityQueue<Data> priorityQueue = new PriorityQueue<>();

        for (int i = 0; i < numbers.length; i++) {
            while (!priorityQueue.isEmpty()) {
                Data data = priorityQueue.peek();

                if (data.num >= numbers[i]) {
                    break;
                }

                answer[data.idx] = numbers[i];
                priorityQueue.poll();
            }

            priorityQueue.add(new Data(i, numbers[i]));
        }
        return answer;
    }

    private void setUp(final int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            arr[i] = -1;
        }
    }
}
