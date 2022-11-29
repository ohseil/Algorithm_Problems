package Problems.연습문제.연속_부분_수열_합의_개수;

import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;

public class Solution {

    private final int NUM_OF_SUBSEQUENCE_INCLUDED_ALL_ELEMENT = 1;

    private class Subsequence {

        int startIdx;
        int numOfDigits;
        int sum;

        public Subsequence(final int startIdx, final int numOfDigits, final int sum) {
            this.startIdx = startIdx;
            this.numOfDigits = numOfDigits;
            this.sum = sum;
        }

        int getNextIdxOfNumToAdd() {
            return (startIdx + numOfDigits) % lenOfElementList;
        }
    }

    private Set<Integer> numSet;
    private Queue<Subsequence> queue;
    private int lenOfElementList;

    private void init(int[] elements) {
        numSet = new HashSet<>();
        queue = new LinkedList<>();
        lenOfElementList = elements.length;
    }

    private void findAllOfSubsequence(int[] elementList) {

        for (int i = 0; i < lenOfElementList; i++) {
            queue.add(new Subsequence(i, 1, elementList[i]));
        }

        while (queue.isEmpty() == false) {

            Subsequence subsequence = queue.poll();

            numSet.add(subsequence.sum);

            if (subsequence.numOfDigits + 1 == lenOfElementList)
                continue;

            subsequence.sum += elementList[subsequence.getNextIdxOfNumToAdd()];
            subsequence.numOfDigits++;
            queue.add(subsequence);
        }
    }

    public int solution(int[] elements) {

        // Subsequence라는 개념을 class로 정의한다.
        // Subsequence 안에는
        // 시작 index, 포함하는 숫자의 개수, 포함 된 숫자의 총 합 정보를 포함한다.
        // 그리고 다음 더해야 할 숫자의 index를 반환하는 함수를 가지고 있다.
        // 다음 더해야 할 숫자의 index = (시작 index + 포함하는 숫자의 개수) % elements의 길이 로 구할 수 있다.
        // 원형이기 때문에 % 연산을 해줘야 한다.

        // elements의 각 원소들을 시작점으로 해서 Subsequence 객체를 만들어서 큐에 삽입한다.
        // 큐에 담겨있는 Subsequence 객체는 빠져나올 때마다,
        // 다음 포함해야 할 숫자를 포함시키고 다시 큐에 삽입된다.
        // 삽입하기 전에 숫자를 포함한 후의 숫자들의 총합을 Hash Set에 저장해서 중복을 제거한 부분 수열의 합들을 구한다.

        // Subsequence를 큐에 다시 삽입하기 전에,
        // Subsequence의 현재 포함 된 숫자의 개수를 확인한다.
        // 숫자의 개수가 elements의 length와 동일하다면 모든 숫자를 포함하는 것이기 때문에
        // 큐에 삽입하지 않는다.
        // 왜냐하면 모든 Subsequence는 결국 모든 숫자를 포함하게 되기 때문에 불필요한 연산을 제거하기 위해서다.
        // 모든 숫자를 포함하는 부분 수열은 유일하게 1개이기 때문에 나중에 더해준다.

        int answer = 0;

        init(elements);
        findAllOfSubsequence(elements);

        answer = numSet.size() + NUM_OF_SUBSEQUENCE_INCLUDED_ALL_ELEMENT;

        return answer;
    }

    public void service() {

        int[] elements = {7,9,1,1,4};

        int answer = solution(elements);
        System.out.println(answer);
    }
}
