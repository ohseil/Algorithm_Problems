package Problems.연습문제.연속된_부분_수열의_합;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * Two Pointers 알고리즘 ( Sliding Windows 알고리즘이라고도 한다. ) 사용
 * Two Pointer 알고리즘을 사용해서 조건에 맞는 모든 구간을 구한 뒤, 조건에 맞게 정렬해서 답을 구한다.
 */

public class Solution {

    private final List<Data> list = new ArrayList<>();

    public void service() {
        final int[] sequence = {1, 1, 1, 2, 3, 4, 5};
        final int k = 5;

        final int[] answer = solution(sequence, k);
        for (int a : answer) {
            System.out.print(a + " ");
        }
    }

    public int[] solution(final int[] sequence, final int k) {
        int[] answer;
        int start = 0;
        int total = 0;

        for (int end = 0; end < sequence.length; end++) {
            if (sequence[end] > k) {
                start = end + 1;
                continue;
            }

            total += sequence[end];

            while (total > k) {
                total -= sequence[start++];
            }

            if (total == k) {
                list.add(new Data(start, end - start));
            }
        }

        Collections.sort(list);

        answer = new int[]{list.get(0).start, list.get(0).start + list.get(0).len};
        return answer;
    }

    static class Data implements Comparable<Data> {

        final int start;
        final int len;

        public Data(int start, int len) {
            this.start = start;
            this.len = len;
        }

        @Override
        public int compareTo(Data o) {
            if (this.len < o.len) {
                return -1;
            } else if (this.len == o.len) {
                return this.start - o.start;
            }
            return 1;
        }
    }
}
